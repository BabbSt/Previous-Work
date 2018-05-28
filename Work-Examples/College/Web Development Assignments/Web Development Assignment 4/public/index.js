var modal=document.getElementById('create-twit-modal');
var background=document.getElementById('modal-backdrop');
var twitContent=document.getElementById('twit-text-input');
var attribute=document.getElementById('twit-attribution-input');

function twitClick (event){
	modal.classList.remove('hidden');
	background.classList.remove('hidden');
}

function closeModal (event){
	modal.classList.add('hidden');
	background.classList.add('hidden');
	twitContent.value="";
	attribute.value="";
	event.stopPropagation;
}

var twitButton = document.getElementById('create-twit-button');
twitButton.addEventListener('click', twitClick);

var exit=document.getElementsByClassName('modal-close-button');
exit[0].addEventListener('click', closeModal);

var cancel=document.getElementsByClassName('modal-cancel-button');
cancel[0].addEventListener('click', closeModal);

var done=document.getElementsByClassName('modal-accept-button');
done[0].addEventListener('click', function(event){
   	if(attribute.value && twitContent.value){
	   	var att=document.createElement('a');
		att.setAttribute('href',"#");
		att.textContent=attribute.value;
		var attP=document.createElement('p');
		attP.appendChild(att);
		attP.classList.add('twit-attribution');
		var text=document.createElement('p');
		text.textContent=twitContent.value;
		text.classList.add('twit-text');
		var content=document.createElement('div');
		content.classList.add('twit-content');
		content.appendChild(text);
		content.appendChild(attP);

		var fas=document.createElement('i');
		fas.classList.add('fas','fa-bullhorn');
		var icon=document.createElement('div');
		icon.classList.add('twit-icon');
		icon.appendChild(fas);

		var twit=document.createElement('article');
		twit.classList.add('twit');
		twit.appendChild(icon);
		twit.appendChild(content);

		var main=document.getElementsByClassName('twit-container');
		main[0].appendChild(twit);
		closeModal(event);
	}else{
		alert("Either your twit content or attribute is missing. Please check again.");
	}
});

var searchButton=document.getElementById('navbar-search-button');
searchButton.addEventListener('click',function(event){
	var allTwits=document.querySelectorAll('.twit-text,.twit-attribution>a');
	var keep;
	var search=document.getElementById('navbar-search-input').value.toLowerCase();
	//console.log(search);
	for(var i=0; i<allTwits.length; i+=2){
	   	keep=0;
		if(allTwits[i].textContent.toLowerCase().indexOf(search)>-1||allTwits[i+1].textContent.toLowerCase().indexOf(search)>-1){
			keep=1;
		}
		if(keep==0){
			allTwits[i].parentNode.parentNode.parentNode.removeChild(allTwits[i].parentNode.parentNode);
		}
	}
});
