function compute_314(N::Int)
    num_landed_in_radcir = 0  # counts number of points that have radial coordinate < 1, i.e. in circle
    for i = 1:N
        a = rand() * 2 - 1  # uniformly distributed number on x-axis
        b = rand() * 2 - 1  # uniformly distributed number on y-axis

        r2 = a*a + b*b  # radius squared, in radial coordinates
        if r2 < 1.0
            num_landed_in_radcir += 1
        end
    end

    return num_landed_in_radcir / N * 4.0
end