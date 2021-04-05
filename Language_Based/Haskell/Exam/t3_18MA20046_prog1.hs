-- Swapnanil Halder
-- 18MA20046

four_squares :: Int -> [(Int, Int, Int, Int)]
four_squares n = [(a, b, c, d) | a <- [0..n], b <- [0..(n-(a*a))], c <- [0..(n-((a*a)+(b*b)))], d <- [0..(n-((a*a)+(b*b)+(c*c)))], (a*a)+(b*b)+(c*c)+(d*d) == n]
-- Iterating through 1..n checking for group of 4 numbers whose squares match the number after summing 


main = do
    print $ four_squares 321