const CONV = 24 * 60 * 60 * 1000;

var today = new Date();
var classes_begin = new Date(year=2021, month=0, date=11);
var classes_end = new Date(year=2021, month=3, date=21);

var num_days_semester = Math.round((classes_end - classes_begin) / CONV);
var num_days_now = Math.round((classes_end - today) / CONV);

var p = (1 - (num_days_now / num_days_semester)) * 100;

if (p > 100) {
    p = 100;
}
else if (p < 0) {
    p = 0;
}

document.getElementById("course-progress").style.width = `${p}%`;
document.getElementById("course-progress-header").textContent = `Semester Progress (${Math.round(p)}%)`
