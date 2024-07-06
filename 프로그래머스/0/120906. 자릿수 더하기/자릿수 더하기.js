function solution(n) {
    let str = `${n}`;
    const answer = str.split("").reduce((acc, current) => acc+ parseInt(current),0);
    return answer;
}