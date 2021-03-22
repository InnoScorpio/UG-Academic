function multiple3to5less(number)
    fullsum = 0
    for x = 1:number
        if ((x%5 == 0) || (x%3 == 0))
            fullsum += x
        end
    end
    return fullsum
end