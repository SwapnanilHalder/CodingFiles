val :: Int
val = 25

mult2 :: Int -> Int
mult2 x = 2*x

summation :: Int -> Int -> Int
summation x y = x+y

fact :: Int->Int
fact 0 = 1
fact x
        | x > 0 = x * fact(x-1)
        | x < 0 = fact(-x)

swap :: (Int, Int) -> (Int, Int)
swap (x, y) = (y,x)

fibo :: Int -> Int
fibo 0 = 1
fibo 1 = 1
fibo x = fibo(x-1) + fibo(x-2)

fibo1 :: Int -> [Int]
fibo1 0 = [1]
fibo1 1 = [1,1]

main = do
        print $ val
        print $ mult2(x)
        print $ summation x y
        print $ fact(z)
        print $ swap(x, y)
        print $ fibo(p)
        where (x, y, z, p) = (3,4, -9, 30)
