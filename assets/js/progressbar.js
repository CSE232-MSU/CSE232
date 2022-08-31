// I usually set these two dates to be the begin/end dates listed on the
// academic calendar: https://reg.msu.edu/roinfo/calendar/academic.aspx
// NOTE: Month is 0 indexed, i.e., 0 = January, 1 = February, ...
const CLASSES_BEGIN = new Date("7/31/2022");
const CLASSES_END = new Date("11/12/2022");

//
// Progress calculation below this point, nothing to worry about here
//

/**
 * Return n if n ∈ [min, max], otherwise return min if n < min, or max if n > max
 * @param {Number} n Value to clamp
 * @param {Number} min Minimum value 
 * @param {Number} max Maximum value
 * @returns {Number} A value in the range [min, max]
 */
function clamp(n, min, max) {
    return Math.max(min, Math.min(n, max));
}

const TODAY = new Date();

const MILLISECONDS_PER_DAY = 24 * 60 * 60 * 1000;
const NUM_DAYS_SEM = Math.round((CLASSES_END - CLASSES_BEGIN) / MILLISECONDS_PER_DAY);
const NUM_DAYS_NOW = Math.round((CLASSES_END - TODAY) / MILLISECONDS_PER_DAY);

let percent = (1 - (NUM_DAYS_NOW / NUM_DAYS_SEM)) * 100;
percent = clamp(percent, 0, 100);

document.getElementById("course-progress").style.width = `${percent}%`;
document.getElementById("course-progress-header").textContent = `Semester Progress (${Math.round(percent)}%)`
