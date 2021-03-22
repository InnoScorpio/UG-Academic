function compute_pi(B::Int)
 
    n_landed_in_circle = 0  
    for i = 1:B
        x = rand() * 2 - 1 
        y = rand() * 2 - 1 

        r2 = x*x + y*y  
        if r2 < 1.0
            n_landed_in_circle += 1
        end
    end

    return n_landed_in_circle / B * 4.0
end

