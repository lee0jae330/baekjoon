function solution(s) {
    s = [...s].sort();
    const array = [...s];
    s = [...new Set([...s])];
    const copy = new Set();
    for(let i=0;i<array.length; i++) {
        for(let j = i+1;j<array.length ;j++) {
            if(array[i] === array[j]) {
                copy.add(array[i]);
            }
        }
    }
    var answer = '';
    s.forEach((ch) => {
        if(!copy.has(ch)) {
            answer +=ch;        
        }
    })
    return answer;
}