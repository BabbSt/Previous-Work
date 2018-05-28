 var movement;
 var level;
 var obstacles= new Map();
 obstacles.set(1,new Set(["http://i.imgur.com/2UYkLTR.png?1","http://i.imgur.com/rFcuhAO.png?1","http://i.imgur.com/3MYPLEX.png?1"]));
 obstacles.set(2,new Set(["http://i.imgur.com/3MYPLEX.png?1","http://i.imgur.com/JtZDTtm.png?1","http://i.imgur.com/h4IlNfs.png?1"]));
 obstacles.set(3,new Set(["http://i.imgur.com/4qVBcmn.png?1","http://i.imgur.com/LlugRYE.png?1","http://i.imgur.com/8cGc3nB.png?1"]));
 obstacles.set(4,new Set(["http://i.imgur.com/JXaAuNU.png?1","http://i.imgur.com/8NBKXwv.png?1","http://i.imgur.com/7606jGq.png?1"]));
 obstacles.set(5,new Set(["http://i.imgur.com/mthOqMZ.png?1","http://i.imgur.com/sjzqwqg.png?1","http://i.imgur.com/X5wUAdI.png?1"]));
 
function init(){
	document.getElementById("pic").fishrow=3;
	document.getElementById("obs1").obsleft=85;
	document.getElementById("obs1").fishrow=1;
	document.getElementById("obs1").currentrow=1;
	document.getElementById("obs1").obsPast=0;
	level=1;
 
}
function startMovement(){
	document.getElementById("obs1").src=getObstacle(obstacles.get(level));
	if(level==2){
		document.getElementById("pic").src="http://i.imgur.com/s9asyrG.png?1";
	}else if(level==3){
		document.getElementById("pic").src="http://i.imgur.com/p5Tjhao.png?1";
	}else if(level==4){
		document.getElementById("pic").src="http://i.imgur.com/w3Xq8ZJ.png?1";
	}else if(level==5){
		document.getElementById("pic").src="http://i.imgur.com/pxseYJN.png?1";
	}
	document.getElementById("levelFacts"+level).style.visibility="hidden";
	document.getElementById("obs1").obsPast=0;
	movement= setInterval(moveObs, 700/level);
}

function moveObs(){
	var o=document.getElementById("obs1");
	
	if(o.obsleft>0){o.obsleft-=10;}
	else {
		document.getElementById("obs1").src=getObstacle(obstacles.get(level));
		o.obsPast+=1;
		o.currentrow=o.fishrow;
		o.obsleft=85; 
		while(o.currentrow==o.fishrow){
			o.fishrow=Math.floor((Math.random() * 3) + 1);
		}
		if(o.fishrow==1){
			o.style.top="2%";
		}else if(o.fishrow==2){
			o.style.top="35%";
		}else if(o.fishrow==3){
			o.style.top="65%";
		}
	}
	document.getElementById("obs1").style.left= o.obsleft+"%";
	if((o.obsleft<=20)&&(document.getElementById("pic").fishrow==o.fishrow)){
		 clearInterval(movement);
		 document.getElementById("gameOver").style.visibility="visible";
	}else
	if(o.obsPast==3){
		clearInterval(movement);
		if(level==5){
		document.getElementById("gameWon").style.visibility="visible";
		}
		level+=1;
		document.getElementById("levelFacts"+level).style.visibility="visible";
		}
	else if(level==3&&o.obsPast==2){
		document.body.style.background= "url(http://i.imgur.com/OCiFNsi.jpg) repeat";
	}
	else if(level==5&&o.obsPast==2){
		document.body.style.background= "url(https://i.imgur.com/RvzYhT0l.jpg)repeat";
	}
}

			
function move (event){
	var p=document.getElementById("pic");
if(event.keyCode==38&&p.fishrow==3){
	p.style="top:35%";
	p.fishrow=2;
	} else
if(event.keyCode==38&&p.fishrow==2){
	p.style="top:2%"
	p.fishrow=1;
	}else
if(event.keyCode==40&&p.fishrow==2){
	p.style="top:65%";
	p.fishrow=3;
	} else
if(event.keyCode==40&&p.fishrow==1){
	p.style="top:35%";
	p.fishrow=2;}
}

function getObstacle(obsSet){
	var obj;
	for(obj of obsSet){
			var temp= obj;
			obsSet.delete(obj);
			return temp;
	}
}