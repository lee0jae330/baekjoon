function solution(my_string) {
    let arr = my_string.split(" ");
    let sum = +arr[0];
    arr.forEach((op, idx) => {
        if(op ==="+") {
            sum += Number(arr[idx+1]);
        } else if(op ==="-") {
            sum -= Number(arr[idx+1]);
        }
    });
    return sum;
}