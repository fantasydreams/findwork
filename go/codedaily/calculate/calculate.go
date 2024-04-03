package calculate
import (
	"fmt"
)

func init() {
	fmt.Println("init ... calculate")
}

//在上面的程序中，Morning 变量是可以被输出的，但是 morning 不行，因为它是以小写字母开头的。
// 需要暴露出去的用大写开头，不需要暴露出去的用小写开头，这语言牛逼！！
// Exported Names
// We capitalized the function Calculate in the Simple interest package. This has a special meaning in Go. Any variable or function which starts with a capital letter are exported names in go. Only exported functions and variables can be accessed from other packages. In our case, we want to access Calculate function from the main package. Hence this is capitalized.

// If the function name is changed from Calculate to calculate in simpleinterest.go, and if we try to call the function using simpleinterest.calculate(p, r, t) in main.go, the compiler will error
func Addfunc2(a, b float64) float64 {
	return a + b
}

func Addfunc3(a, b, c float64) float64 {
	return a + b + c
}

func Test() {
	fmt.Println("this is test func")
}