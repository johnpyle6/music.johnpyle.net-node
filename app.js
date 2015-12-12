/**
 * TODO:
 * - Standard 404, 403, 500 messages
 * - reduce functions
 * - oopize
 */



var connect = require('connect')
    , http = require('http')
    , fs = require('fs')
    , path = require('path')
    , ms = require('multistream');

function send404(response) {
    response.writeHead(404, { 'Content-Type': 'text/plain' });
    response.write('Error 404: Resource not found.');
    response.end();
}

function mimeLookup(ext){
	var success = false;
	var mimeTypes = {
	    '.js': 'application/javascript',
	    '.html': 'text/html',
	    '.mp3' : 'audio/mpeg',
	    '.css' : 'text/css',
	    '.jpg' : 'image/jpeg',
	    '.ttf' : 'application/x-font-ttf'
	};
	 
	if (mimeTypes[ext]){
		success = mimeTypes[ext]; 
	}
	
	return success;
}

function composeStream(filepath, ext){
	var streams = false;
	if (ext == ".html"){
		var fileheader = path.resolve("music/top.html");
		streams = [ fs.createReadStream(fileheader) ];
		streams.push(fs.createReadStream(filepath));
	}else{
		streams = [ fs.createReadStream(filepath) ];
	}
	
	var base = path.basename(filepath, '.html'); 
	if ( base == 'originals' || base == "demo"){
    	var player = path.resolve("music/jplayer.html");
    	streams.push(fs.createReadStream(player));
	}
	
    return streams;
}

function getResource(req, res, next) {
    if (req.method == 'GET') {
        // resolve file path to filesystem path
        var fileurl;
        if (req.url == '/')
            fileurl = '/index.html';
        else
            fileurl = req.url;
        
        
        /* TODO: Differentiate between non-existent or outside directory or is that necessary? */
        var fileExt = path.extname(fileurl);
        var filepath = path.resolve("music", fileurl.substring(1));
        //console.log( path.dirname(filepath).substring(0,19) );
         
        
        
        fs.exists(filepath, function (exists) {
        	if (!exists){
        		send404(res);
        	}else{
	        	mimeType = mimeLookup(fileExt);
	        	//console.log(mimeType);
	        	
	        	headers = {
	        		'Content-Type' : mimeType,
	        		'Server' : 'Node.js',
	        		'Last-Modified' : 'Fri, 11 Dec 2015 02:32:10 GMT',
	        	}
	        	
	        	if (mimeType) {
	        		var streams = composeStream(filepath, fileExt);
	        		var status = '200';
	        		if (req.headers['if-modified-since'])
	        			status = '304';
	        		
	        		res.writeHead(status, headers);
	    	        ms(streams).pipe(res) // => 123
	            }else{
	            	// more appropriate message
	    	        send404(res);
	            }
        	}
        });
        
        
        //console.log(streams);
    }
    else {
        send404(res);
    }
}

connect()
    .use(getResource)
    .listen(3000);
/**
 * New node file
 */
