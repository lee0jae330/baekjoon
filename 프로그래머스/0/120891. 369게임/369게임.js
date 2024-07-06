function solution(order) {
    var answer = [...`${order}`].filter((num)=> num==="3" || num === "6" || num ==="9").length;
    return answer;
}