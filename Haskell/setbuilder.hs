{-
set builder notation

S1 = {x|x {belongs to {0},N}, x satisfies something}
similar representation for list is Haskell is called list comprehension
-}

main = do
	let l1=[20, 18.. 6]
	let l2 = []
	let l3 = [3,2 ,5,4,3,25]
	print $ [x*x|x <- l3,mod x 2==0]
	print $ [(a,b,c) | a <- [1..100] , b <- [1..100] , c <- [1..100] , a*a+b*b == c*c]
	