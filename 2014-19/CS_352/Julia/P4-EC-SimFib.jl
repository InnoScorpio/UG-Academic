function SumFibEvens_below(num)
    fib_num_prev = 1
    fib_num = 1
    fib_sum = 0
    answer = 0
    
    while fib_sum < num
        fib_sum = fib_num_prev + fib_num
        fib_num_prev = fib_num
        fib_num = fib_sum
        if fib_sum%2 == 0
            answer += fib_sum
        end
    end
    return answer
end
