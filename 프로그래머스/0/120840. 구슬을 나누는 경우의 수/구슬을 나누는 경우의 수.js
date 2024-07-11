const arr = [];

function init() {
    for(let i =0;i<31; i++) {
        arr.push(new Array(31).fill(0));
    }

    for(let i =1;i<31; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    
    for(let i = 2;i<31;i++) {
        for(let j=1;j<=i;j++) {
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }
}




function solution(balls, share) {
    init();
    console.log(arr[balls][share]);
    return arr[balls][share];
}