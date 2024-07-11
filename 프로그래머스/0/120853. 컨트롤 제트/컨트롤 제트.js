function solution(s) {
    s = s.split(" ");
    let sum =0;
    s.forEach((c, idx) => {
        if(c=== "Z") {
            sum -= Number(s[idx-1]);
        } else {
            sum += Number(c);
        }
    })
    return sum;
}