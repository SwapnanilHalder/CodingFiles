type Rat = (Int,Int)

makeRat :: Int -> Int -> Rat
makeRat x 0 = error ( "Cannot construct a rational number "
                       ++ showRat (x,0) ++ "\n" ) 
makeRat 0 y = (0,1) 
makeRat x y = (x,y)

numer, denom :: Rat -> Int
numer (x,y) = x' `div` d
    where x' = (signum' y) * x 
          y' = abs' y 
          d  = gcd' x' y'

denom (x,y) = y' `div` d
    where x' = (signum' y) * x
          y' = abs' y 
          d  = gcd' x' y'

showRat :: Rat -> String
showRat x = show (numer x) ++ "/" ++ show (denom x)

signum' :: Int -> Int
signum' n | n == 0 =  0 
          | n > 0  =  1 
          | n < 0  = -1
            
abs' :: Int -> Int 
abs' n | n >= 0 =  n 
       | n <  0 = -n 
 
gcd' :: Int -> Int -> Int 
gcd' x y = gcd'' (abs' x) (abs' y) 
         where gcd'' x 0 = x 
               gcd'' x y = gcd'' y (x `rem` y)

main = do
    let n1 = Rat 5 2