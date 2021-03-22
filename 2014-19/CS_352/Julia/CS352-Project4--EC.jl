function multiple3or5(no)
    total_sum = 0
    for u = 1:no
        if ((u%5 == 0) || (u%3 == 0))
            total_sum += u
        end
    end
    return total_sum
end