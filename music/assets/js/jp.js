$(document).ready(function(){
      $("#jquery_jplayer_1").jPlayer({
        cssSelectorAncestor: "#jp_container_1",
        swfPath: "/js",
        supplied: "mp3",
        useStateClassSkin: true,
        autoBlur: false,
        smoothPlayBar: true,
        keyEnabled: true,
        remainingDuration: true,
        toggleDuration: true
      });
      
      
      
      $("#why").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Why",
    		  mp3: "originals/why.mp3",
    	  }).jPlayer("play");
      });
      
      $("#wonder").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Wonder",
    		  mp3: "originals/wonder.mp3",
    	  }).jPlayer("play");
      });
      
      $("#dawnsong").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Song for Dawn",
    		  mp3: "originals/dawnsong.mp3",
    	  }).jPlayer("play");
      });
      
      $("#andstop").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "And Stop",
    		  mp3: "originals/andstop.mp3",
    	  }).jPlayer("play");
      });
      
      $("#backAndForth").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Back and Forth",
    		  mp3: "originals/backandforthpreproduction.mp3",
    	  }).jPlayer("play");
      });
      
      $("#depend").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Depend",
    		  mp3: "originals/depend.mp3",
    	  }).jPlayer("play");
      });
      
      $("#comeback").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Come Back to My Heart",
    		  mp3: "originals/comeback.mp3",
    	  }).jPlayer("play");
      });
      
      $("#sarah").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Sarah",
    		  mp3: "originals/sarah.mp3",
    	  }).jPlayer("play");
      });
      
      $("#history").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "The History",
    		  mp3: "originals/the_history.mp3",
    	  }).jPlayer("play");
      });
      
      
      // Demo
      $("#Whats-Going-On").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "What's Going On",
    		  mp3: "demo/john-pyle-trio-whats-going-on.mp3",
    	  }).jPlayer("play");
      });
      
      $("#Come-Together").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Come Together",
    		  mp3: "demo/john-pyle-trio-come-together.mp3",
    	  }).jPlayer("play");
      });
      
      $("#Superstition").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Superstition",
    		  mp3: "demo/john-pyle-trio-superstition.mp3",
    	  }).jPlayer("play");
      });
      
      $("#Overkill").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Overkill",
    		  mp3: "demo/john-pyle-trio-overkill.mp3",
    	  }).jPlayer("play");
      });
      
      $("#rain").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Have You Ever Seen the Rain",
    		  mp3: "demo/john-pyle-have-you-ever-seen-the-rain.mp3",
    	  }).jPlayer("play");
      });
      
      $("#Breakfast-at-Tiffanys").click(function(){
    	  $("#jquery_jplayer_1").jPlayer("setMedia", {
    		  title: "Breakfast at Tiffany's",
    		  mp3: "demo/john-pyle-breakfast-at-tiffanys.mp3",
    	  }).jPlayer("play");
      });
    });