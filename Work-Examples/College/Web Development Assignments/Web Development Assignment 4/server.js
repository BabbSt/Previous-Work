/* Name: Stephanie Babb
 * Email: babbst@oregonstate.edu
 */
var fs = require('fs');
var http = require('http');

var html = fs.readFileSync('./public/index.html','utf8');
var js = fs.readFileSync('./public/index.js','utf8');
var css = fs.readFileSync('./public/style.css','utf8');
var notFound = fs.readFileSync('./public/404.html','utf8');

function requestHandler(req,res){
	if(req.url =='/index.html'|| req.url=='/'){
		res.statusCode = 200;
		res.write(html);
	}else if(req.url == '/style.css'){
		res.statusCode = 200;
		res.write(css);
	}else if(req.url == '/index.js'){
		res.statusCode = 200;
		res.write(js);
	}else{
		res.statusCode = 404;
		res.write(notFound);
	}
	res.end();
}

var server = http.createServer(requestHandler);
if(process.env.PORT){
	server.listen(process.env.PORT);
}else{
	server.listen(3000);
}
