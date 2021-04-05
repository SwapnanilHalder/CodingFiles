cube_root :: Integer -> Integer
cube_root x = ceiling (fromIntegral x**(1/3)) + 1

is_sum_of_cubes :: Integer -> [(Integer, Integer)]
is_sum_of_cubes n
    -- Iterating x and y throughout the range to see, if there is two combinations of sum of cubes that matches the number of not
    | length([(x,y) | x<-[1..cube_root n],y<-[1..n-x*x*x], x<y, x*x*x+y*y*y==n]) >1 = [(x,y) | x<-[1..cube_root n], y<-[1..n-x*x*x], x<y, x*x*x + y*y*y == n]
    -- If we can't find at least two combinations of sum of cubes
    | otherwise = []

main = do
    print $ is_sum_of_cubes 1729
    print $ is_sum_of_cubes 4104
    print $ is_sum_of_cubes 20683
    print $ is_sum_of_cubes 13832
    print $ is_sum_of_cubes 172
