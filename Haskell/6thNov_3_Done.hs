-- Function to determine which elements will go in the first part of the divided array
lesser :: Int -> [Int] -> [Int]
lesser p ps = filter (< p) ps

--Function to determine which elements will go in the last(third) part of the divided array
greater :: Int -> [Int] -> [Int]
greater p xs = filter (>= p) xs 

quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) =
    let smaller = lesser x xs
        larger = greater x xs
-- dividing the whole array recursively in three parts,
-- first part consists of all the elements smaller than the 1st index element in the selected list(sublist)
-- second part consists of all the elements larger(or, equal) than the 1st index element in the selected list(sublist)
    in  quicksort smaller ++ [x] ++ quicksort larger

main::IO()
main = do
    let a = [15, 30, 12, 10, 5 , 4, -56, -96,0]
    print $ quicksort a