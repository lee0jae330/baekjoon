function solution(numbers) {
    var answer = numbers.reduce((acc, current) => {
        return acc + current;
    });
    return answer / numbers.length;
}