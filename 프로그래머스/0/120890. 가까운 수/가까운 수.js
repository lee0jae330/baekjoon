function solution(array, n) {
    array.sort((a,b) => a-b);
    let gap = Math.abs(n-array[0]);
    let sol = array[0];
    
    for(let i =1 ;i<array.length;i++) {
        const g = Math.abs(n-array[i]);
        if(g < gap) {
            gap = g;
            sol = array[i];
        }
    }
    
    return sol;
}