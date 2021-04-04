newreverse::[Integer] -> [Integer]
newreverse [ ] = [ ]
newreverse (x:xs) = newreverse xs ++ [x]

