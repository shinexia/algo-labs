module HelloWorldSpec where

import Control.Monad
import Test.Hspec
import Text.Printf

import HelloWorld

main :: IO ()
main = hspec spec

spec :: Spec
spec = do
  forM_ cases $ \(a, b, expected) ->
    it (printf "add %d %d shouldBe %d" a b expected) $
      add a b `shouldBe` expected
  where
    cases :: [(Int, Int, Int)]
    cases = [
        (1, 2, 3),
        (1, 10, 11)
      ]

