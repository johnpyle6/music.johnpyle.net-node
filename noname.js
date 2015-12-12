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
	    '.jpg' : 'image/jpeg'
	    //'.ttf' : ''
	};
	 
	if (mimeTypes[ext]){
		success = true; 
	}
	
	return success;
}

function composeStream(filepath, ext){
	var streams = false;
	var fileheader = path.resolve("music/top.html");
    
    streams = [ fs.createReadStream(fileheader) ];
	if (ext == ".html"){
		streams.push(fs.createReadStream(filepath));
		
		/*
		var base = path.basename(filepath, '.html'); 
		if ( base == 'originals' || base == "demo"){
	    	var player = path.resolve("music/jplayer.html");
	    	streams.push(fs.createReadStream(player));
	    }*/
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
        
        var filepath = path.resolve(fileurl.substring(1));
        var fileExt = path.extname(filepath);
        fs.exists(filepath, function (exists) {
        	mimeType = mimeLookup(fileExt);
        	
        	if (mimeType) {
        		var streams = composeStream(filepath, fileExt);
        		console.log(streams.length);
        		res.writeHead(200, { 'content-type': mimeType });
    	        ms(streams).pipe(res) // => 123
            }else{
    	        send404(res);
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
