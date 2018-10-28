

everything in JS are objects, arrays, a variable, In JS you can but object within object

anonymous functions, aka lamda functions


//array nums
var nums = [1,2,3,4,5];


//using an anonymous function here, no need to give it a name when you're most likely not gonna use it again
//map iterates through the array
nums = nums.map(function(num)) {
    return num * 2;
};

events in html and JS are some sort of actions: a mouse click, a page finished loading, a hover, user type something

JS has event handlers, which are callback functions that responds to HTML events. This allows websites to be very interactive

//in the HTML file
<html>
    <head>
        <title>Event Handlers</title>
    </head>
    <body>
        <button onclick="alertName(event)">Button1</button>
        <button onclick="alertName(event)">Button2</button>
    </body>
</html>

//in the JS file
function alertName(event)
{
    let trigger = event.srcElement;  //find the source element
    alert("you clicked on " + trigger.innnerHTML)  //inform the user
}


DOM: document object model wraps the whole webpage into an object and allow you to manipulate the page's element progammatically

using javascript without going to the HTML file or the Python file

DOM represents a webpage in form of a tree

DOM itself is an object, thus it has methods and properties that can be used to manipulate every specific piece of a website
by playing with these properties and methods, the contents of the page can change without needing to refresh the page


DOM properties:
innerHTML : holds the HTML inside a set of HTML tags
nodeName  : the name of an HTML element or element's attribute
id        : the id attribute of an HTML element
parentNode: a reference to the node one level up in the DOM
childNods : an array of references to the nodes one level down in the DOM
attributes: an array of attributes of an HTML element
style     : an object encapsulating the CSS/HTML styling of an element

DOM methods:
getElementById(id)       : gets the elemnt with a given ID below this point in the DOM
getElementsByTagName(tag): gets all elements with the given tag below this point in the DOM
appendChild(node)        : add the given node to the DOM below this point
removeChild(node)        : remove the specified child node from the DOM

As you can see, these methods are quite lengthy, this is where jQuery comes in.
jQuery is a popular library that is designed to simplify client-side scripting (such as DOM manipulations)

//change background color of one section of a page to green using plain JS DOM
document.getElementById('colorDiv').style.backgroundColor = 'green'
//same in jQuery, shorter but more cryptic
$('#colorDiv').css('background-color', 'green');

with jQuery, we can manipulate things on the client side but haven't really interact with other webpages, this is where AJAX comes in.

AJAX is a JS technique that allows us to even more dynamically update a webpage. Refresh a section of a page instead of a whole page.
think of scrolling through FB, only the newsfeed change and nothing else. Within the newsfeed you can intereact with other features/sites
or score of games updating in realtime on a page.

AJAX uses a special JS object called an XMLHttpRequest to asynchronously update our pages
var xhttp = new XMLHttpRequest();

After obtaining the object, you need to define its onreadystatechange behavior:
    this function(usually an anonymous funtion), a call back function,  that will be called when the asynchronous HTTP request
    has completed, and thus defines what is expected to change on your site.

there are 5 different states. 0 to 4, 4 is finished, status 200 OK, then make your asynchronous request using the open()
    method to define the request and the send() method to actually send it.

AJAX requests are usually written in jQuery syntax.

//this example is in vanilla javascript
function ajax_request(argument)
{
    var aj = new XMLHttpRequest();
    aj.onreadystatechange = function() {
        if aj.readyState == 4 & aj.status == 200)
            //do something here like get information from that url bellow
    };
    aj.open("GET", /* url */, true);
    aj.send();
}







