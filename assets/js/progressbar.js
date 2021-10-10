// Conversion factor to go from milliseconds to days (difference between
// Date objects returns a number in milliseconds... for some reason)
const MILLISECONDS_PER_DAY = 24 * 60 * 60 * 1000;

// Date of execution time
let today = new Date();

// I usually set these two dates to be the begin/end dates listed on the
// academic calendar: https://reg.msu.edu/roinfo/calendar/academic.aspx
// NOTE: Month is 0 indexed, i.e., 0 = January, 1 = February, ...
let classes_begin = new Date(2021, 8, 1);
let classes_end = new Date(2021, 11, 18);

//
// Progress calculation below this point, nothing to worry about here
//

let num_days_semester = Math.round((classes_end - classes_begin) / MILLISECONDS_PER_DAY);
let num_days_now = Math.round((classes_end - today) / MILLISECONDS_PER_DAY);

let p = (1 - (num_days_now / num_days_semester)) * 100;
if (p > 100) {
    p = 100;
}
else if (p < 0) {
    p = 0;
}

document.getElementById("course-progress").style.width = `${p}%`;
document.getElementById("course-progress-header").textContent = `Semester Progress (${Math.round(p)}%)`
