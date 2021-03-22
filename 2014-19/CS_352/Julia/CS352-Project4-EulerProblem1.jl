function Mult3or5_below(num)
    sum_all = 0
    for i = 1:num
        if ((i%5 == 0) || (i%3 == 0))
            sum_all += i
        end
    end
    return sum_all
end