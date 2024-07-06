function solution(n, k) {
    var answer = 12000 * n + 2000 * ((k-(Math.floor(n/10)))<0 ? 0 : k-(Math.floor(n/10)));
    return answer;
}