function solution(array) {
    const set = new Set(array);
    const result = [];
    for(let num of set) {
        let cnt =0;
        array.forEach((n)=> {
            if(n === num ) {
                cnt++;
            }
        })
        result.push([num, cnt]);
    }
    result.sort((a,b) => {
       return a[1] - b[1];
    })
    console.log(result);
    console.log(result.length);
    if(result.length > 1) {
        return (result[result.length-1][1] === result[result.length-2][1]) ? -1 : result[result.length-1][0]; 
    }
    return result[result.length-1][0];
}