
// 1. strings
var str1 = "It's six o'clock.";
var str2 = 'Rememver to say "please" and "thank you".';

var str3 = str1 + str2;

// 2. numbers
var num1 = 2;
var num2 = 2.2;

var res1 = num1 + num2;
var res2 = num1 - num2;
var res2 = num1 * num2;
var res2 = num1 / num2;

// 3. booleans
var isBig = false;
isBig = true;

// 4. variables
var camelCase = "lowercase word, then uppercase";
var dinner2Go = "pizza";
var I_AM_HUNGRY = true;
var _Hello_ = "what a nice greeting"
var $_$ = "money eyes";

// 5. functions
function addTwoNumbers(x, y) {
    return x + y;
}

// 6. conditionals
if (false) {
    var outcome = "if block";
} else if (true) {
    var outcome = "else if block";
} else {
    var outcome = "else block";
}
// 7. arrays
var hodgepodge = [100, "paint", [200, "brush"], false];
    // push pop length concat reverse join
    // var list = str2.split(" ");
// 8. objects
var course = {
    name: "GRA 2032",
    start: 8,
    end: 10
};
course.begin = function begin(){
    return "Course begin from " + this.start;
}

course.name;
course.begin();
