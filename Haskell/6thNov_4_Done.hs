quicksort :: [Int] -> [Int]
quicksort [] = []
-- dividing the whole array recursively in three parts,
-- first part consists of all the elements smaller than the 1st index element in the selected list(sublist)
-- second part consists of all the elements larger(or, equal) than the 1st index element in the selected list(sublist)
quicksort (x:xs) = 
    quicksort [i | i <- xs, i < x] ++ [x] ++ quicksort [i | i <- xs, i >= x]

main::IO()
main = do
    let a = [15, 30, 12, 10, 5 , 4, -56, -96,0]
    print $ quicksort a