package main

import (
	"codedaily/calculate"
	"context"
	"encoding/json"
	"fmt"
	"math"
	"reflect"
	"runtime/debug"
	"sync"
	"time"
)

type ArticleResponse struct {
	ArticleTitle     *string `protobuf:"bytes,1,opt,name=article_title,json=articleTitle" json:"article_title,omitempty"`
	ArticleContent   *string `protobuf:"bytes,2,opt,name=article_content,json=articleContent" json:"article_content,omitempty"`
	XXX_unrecognized []byte  `json:"-"`
}

func Do(fn func()) {
	defer func() {
		if err := recover(); err != nil {

		}
	}()

	fn()
}

func DoAsync(fn func()) {
	go func() {
		defer func() {
			if err := recover(); err != nil {
			}
		}()

		fn()
	}()
}

func DoWithCtx(ctx context.Context, fn func()) {
	defer func() {
		if err := recover(); err != nil {
		}
	}()

	fn()
}

func DoAsyncWithCtx(ctx context.Context, fn func()) {
	go func() {
		defer func() {
			if err := recover(); err != nil {
			}
		}()

		fn()
	}()
}

func DoAsyncWithCtx1(ctx context.Context, fn func(...any), para ...any) {
	go func() {
		defer func() {
			if err := recover(); err != nil {
			}
		}()

		fn(para...)
	}()
}

func DoAsyncWithCtxCancel(ctx context.Context, fn func()) {
	go func() {
		defer func() {
			if err := recover(); err != nil {
			}
		}()
		// for {
		select {
		case <-ctx.Done():
			fmt.Println("cancel11111")
			return
		default:
			fn()
		}
		// }
	}()
}

// WithLock runs while holding lk.
func WithLock(mutex *sync.Mutex, fn func()) {
	mutex.Lock()
	defer mutex.Unlock()
	fn()
}

type RoutineGroup struct {
	waitGroup sync.WaitGroup
}

func NewRoutineGroup() *RoutineGroup {
	return new(RoutineGroup)
}

// Run runs the given fn in RoutineGroup.
// Don't reference the variables from outside,
// because outside variables can be changed by other goroutines
func (g *RoutineGroup) Run(fn func()) {
	g.waitGroup.Add(1)

	go func() {
		defer g.waitGroup.Done()
		fn()
	}()
}

// RunSafe runs the given fn in RoutineGroup, and avoid panics.
// Don't reference the variables from outside,
// because outside variables can be changed by other goroutines
func (g *RoutineGroup) RunSafe(fn func()) {
	g.waitGroup.Add(1)

	DoAsync(func() {
		defer g.waitGroup.Done()
		fn()
	})
}

func (g *RoutineGroup) RunSafeWithCtx(ctx context.Context, fn func()) {
	g.waitGroup.Add(1)

	DoAsyncWithCtx(ctx, func() {
		defer g.waitGroup.Done()
		fn()
	})
}

func (g *RoutineGroup) RunSafeWithCtx1(ctx context.Context, fn func(...any), para ...any) {
	g.waitGroup.Add(1)

	DoAsyncWithCtx1(ctx, func(...any) {
		defer g.waitGroup.Done()
		fn(para...)
	})
}

func (g *RoutineGroup) RunSafeWithCtxCancel(ctx context.Context, fn func()) {
	g.waitGroup.Add(1)
	go DoAsyncWithCtxCancel(ctx, func() {
		defer func() {
			g.waitGroup.Done()
		}()
		fn()
	})

}

// Wait waits all running functions to be done.
func (g *RoutineGroup) Wait() {
	g.waitGroup.Wait()
}

func init() {
	fmt.Println("init ... main")
}

func test(a int, b int) {
	fmt.Println("a + b = ", a+b)
}

// multi return values

func rectProps(length, width float64) (float64, float64) {
	area := length * width
	perimeter := (length + width) * 2
	return area, perimeter
}

// named return values
func rectProps1(length, width float64) (area float64, perimeter float64) {
	area = length * width
	perimeter = (length + width) * 2
	// return area, perimeter
	return // no explicti return value
}

type Data struct {
	Item int
}

func deal(data interface{}) {
	field, ok := data.(*Data)
	if ok {
		field.Item = 1
	}
	data = field
	fmt.Println(data, field)
	fmt.Printf("%T", data)
}

func deal1(date interface{}) {
	deal(&date)
}

type Person struct {
	name   string
	age    int
	height float32
	high   float32
}

// func (p Person) changeTest(newName string) {
// 	p.name = newName
// 	p.age = 18
// 	p.height = 110
// 	p.high = 180
// }

// func (p *Person) changeTest() { // same as func changeTest above, compiler will complain
// 	p.name = "sharwen luo"
// 	p.age = 18
// 	p.height = 110
// 	p.high = 180
// }

func (p *Person) changeTest(newAge int) { // same as func changeTest above, compiler will complain
	p.name = "sharwen luo"
	p.age = newAge
	p.height = 110
	p.high = 180
}

type Employee struct {
	name string
	age  int
}

/*
Method with value receiver
*/
func (e Employee) changeName(newName string) {
	e.name = newName
}

/*
Method with pointer receiver
*/
func (e *Employee) changeAge(newAge int) {
	e.age = newAge
}

// method is not allowd to builtin type, if you alias builtin types in same package, will be support
type myInt int

func (i myInt) add(b myInt) myInt {
	return i + b
}

type VowelsFinder interface {
	FindVowels() []rune
}

type myString string

// implement interface
func (str myString) FindVowels() []rune {
	var vowels []rune
	for _, num := range str {
		if num == 'a' || num == 'e' || num == 'o' || num == 'u' || num == 'i' {
			vowels = append(vowels, num)
			fmt.Printf("%c", num)
		}
	}
	return vowels
}

func findType(i interface{}) {
	switch i.(type) {
	case rune, int:
		fmt.Println("int type")
	case string:
		fmt.Println("string")
	case float32, float64:
		fmt.Println("float type")
	default:
		fmt.Println("unkwnown type")
	}
}

func writeChannel(ch chan int) {
	for i := 1; i <= 10; i++ {
		ch <- i
	}
	close(ch)
}

func server1(ch chan string) {
	ch <- "from server1"
}
func server2(ch chan string) {
	ch <- "from server2"
}

func fullName(firstName *string, lastName *string) {
	// defer fmt.Println("fullname def")
	// defer recovery()
	if firstName == nil {
		panic("runtime error: first name cannot be nil")
	}
	if lastName == nil {
		panic("runtime error: last name cannot be nil")
	}
	fmt.Printf("%s %s\n", *firstName, *lastName)
	fmt.Println("returned normally from fullName")
}

func recovery() {
	if r := recover(); r != nil {
		fmt.Println("recovered:", r)
		debug.PrintStack()
	}
}

// GetGID get go routine id
func GetGID() string {
	return fmt.Sprintf("%d", 0)
}

func getstring(a string) {
	fmt.Println(&a)
}

func handle(ctx context.Context, duration time.Duration) error {
	select {
	case <-ctx.Done():
		fmt.Println("handle", ctx.Err())
	case <-time.After(duration):
		fmt.Println("process request with", duration)
	}
	return nil
}

func main() {
	fmt.Println("hello word")

	var age int // default assined value is 0
	fmt.Println("age is", age)
	age = 18

	fmt.Println("new age is", age)

	// type inference

	var num = 568
	fmt.Println("num is", num)

	var str = "hello word 2"
	fmt.Println("string is", str)

	// multiple variables declaration
	var width, height int = 110, 165
	fmt.Println("width, height are", width, height)
	fmt.Println("width is", width, "height is", height)

	//mutiple variables declaration with inference
	var name, sex = "zhangsan", "male"
	fmt.Println(name + ", " + sex)

	// mutiple varibles declaration with different types

	var (
		car   string  = "BYD han dynasty"
		year  int     = 3
		money float64 = 19.8
	)

	fmt.Println("car brand is", car, "used years", year, "speed monry", money)

	//short hand variable declaration
	buildingname, high := "building name", 100.8
	fmt.Println("building name", buildingname, "high", high)

	// math operation
	a, b := 1.6, 2.8
	c := math.Min(a, b)
	fmt.Println("min value of a", a, "and b", b, "is c", c)

	// type
	// bool
	t := true
	f := false
	fmt.Println("go true", t, "go fasle", f)

	// signed integers
	// int8 -128 ~ 127 10^2
	var int8_max int8 = 127
	var int8_min int8 = -128
	fmt.Println("int8 min:", int8_min, "int8 max:", int8_max)

	int8_max += 1
	fmt.Println("int8_max += 1", int8_max)

	// int16
	// -2^15 ~ 2^15 - 1  -32768 to 32767  量级 3 * 10^5
	var int16_min int16 = -32768
	var int16_max int16 = 32767
	fmt.Println("int16 min:", int16_min, "int16 max:", int16_max)

	// int32
	// -2^31 ~ 2^31 - 1 	-2147483648 to 2147483647 量级 2 * 10 ^ 10
	var int32_min int32 = -2147483648
	var int32_max int32 = 2147483647
	fmt.Println("int32 min:", int32_min, "int32 max:", int32_max)

	// int 64
	// 量级 9 * 10 ^ 19
	var int64_min int64 = -9223372036854775808
	var int64_max int64 = 9223372036854775807
	fmt.Println("int64 min:", int64_min, "int64 max:", int64_max)

	// unsinged intergers
	// 0 ~ 255 2 * 10^2
	var uint8_min uint8 = 0
	var uint8_max uint8 = 255
	fmt.Println("uint8 min:", uint8_min, "uint8 max:", uint8_max)

	// uint16
	// 0 ~ 65535 6 * 10^5
	var uint16_min uint16 = 0
	var uint16_max uint16 = 65535
	fmt.Println("uint16 min:", uint16_min, "uint16 max:", uint16_max)

	// uint32
	// 0 ~ 4294967295 4 * 10^10
	var uint32_min uint32 = 0
	var uint32_max uint32 = 4294967295

	fmt.Println("uint32 min:", uint32_min, "uint32 max:", uint32_max)

	// uint64
	// 0 ~ 18446744073709551615 18 * 10 ^ 19 1 * 10 ^ 20
	var uint64_min uint64 = 0
	var uint64_max uint64 = 18446744073709551615
	fmt.Println("uint64 min:", uint64_min, "uint64 max:", uint64_max)

	// floatting type float32 float64
	var float32_num float32 = 3.1415926
	var float64_num float64 = 3.141592654
	fmt.Println("float32 number is", float32_num, "\n", "float64 number is", float64_num)
	// fmt.Println("type float32_num is float32_num %T", float32_num) not support any more ?
	fmt.Println("type float32_num is", reflect.TypeOf(float32_num), "type float64_num is", reflect.TypeOf(float64_num))

	// complext type
	c1 := 6 + 7i
	c2 := 7 + 8i
	fmt.Println("c1 ", c1, " + c2", c2, "=", c1+c2)

	// uint8 as byte
	// int32 as rune

	// string
	var surname string = "luo"
	var secondname string = "shengwen"
	fmt.Println("name is", surname+" "+secondname)

	// type convert, no implict convert in go, we should use type convert explict
	var num1 rune = 568
	var float_num float64 = 3.141592654
	//var ans = num1 + float_num // ./helloword.go:144:12: invalid operation: num1 + float_num (mismatched types rune and float64)
	var ans = float64(num1) + float_num
	fmt.Println("ans is", ans)

	name = "luoshengwen"
	fmt.Println("name is", name)

	// const variables fix value
	const pi float64 = 3.141592654
	fmt.Println("pi is", pi)

	// declareing a group of constants The value of a constant should be known at compile time
	const (
		name1 = "sharwen"
		age1  = 29
		sex1  = "male"
	)

	fmt.Println("name is", name1, "age", age1, "sex is", sex1)

	test(1, 2)

	area, perimeter := rectProps(1.5, 2)
	fmt.Println("area, perimeter:", area, perimeter)

	area1, perimeter1 := rectProps1(1.5, 2)
	fmt.Println("area1, perimeter1:", area1, perimeter1)

	// _ is known as the blank identifier， the _ variable will be discard
	area2, _ := rectProps1(3, 1.5)
	fmt.Println("area is ", area2)

	// test for add package

	sum := calculate.Addfunc3(1, 2, 4)
	fmt.Println("sum is", sum)
	calculate.Test()

	// if statement syntax
	odd, even := 1, 2
	if odd%2 == 1 {
		fmt.Println("odd", odd, "is an odd number")
	} else {
		fmt.Println("odd", odd, "is an even number")
	}

	if even%2 == 0 {
		fmt.Println("even", even, "is an even number")
	} else {
		fmt.Println("even", odd, "is an odd number")
	}

	// for statement
	for i := 1; i <= 10; i++ {
		if i > 5 {
			break
		}
		fmt.Printf("%d ", i)
	}
	fmt.Println("\nline after for loop")

	// swith
	switch k := 3; k {
	case 1:
		fmt.Println("1")
	case 2:
		fmt.Println("2")
	case 3, 4, 5: // mutiple expressions
		fmt.Println("3")
	default:
		fmt.Println("other")
	}

	// switch expressionless swith
	k := 68
	switch {
	case k < 0:
		fmt.Println("less than zero")
	case k >= 0 && k <= 100:
		fmt.Println("val between 0 - 100")
		fallthrough // next case will be execute although condition is false
	case k > 100 && k <= 1000:
		fmt.Println("large than 100 less equal than 1000")
	default:
		fmt.Println("large than 1000")
	}

	// array and slice
	arrnum := []int{1, 2, 3} // arrnum is reference of a new array
	for i, _ := range arrnum {
		arrnum[i]++
		fmt.Printf("%d ", arrnum[i])
	}

	// append function for slice

	var arrnil []string
	if arrnil == nil {
		arrnil = append(arrnil, "sharwenluo", "is", "handsome")
		fmt.Println(arrnil)
	}

	// append one slice to another use ...
	arrOne := []string{"this", "person"}
	arrOne = append(arrOne, arrnil...)
	fmt.Println(arrOne)

	// pass slice to function will deal as reference

	//pointer to struct

	pPerson := &Person{
		name:   "sharwen",
		age:    30,
		height: 110,
		high:   165,
	}

	fmt.Println(pPerson)
	fmt.Println(pPerson.name, pPerson.age, pPerson.height, pPerson.high)
	fmt.Println((*pPerson).name, (*pPerson).age, (*pPerson).height, (*pPerson).high)

	// recevier for method
	newPerson := *pPerson
	fmt.Println("before change", newPerson)

	(&newPerson).changeTest(18)
	fmt.Println("after change", newPerson)

	e := Employee{
		name: "Mark Andrew",
		age:  50,
	}
	fmt.Printf("Employee name before change: %s", e.name)
	e.changeName("Michael Andrew")
	fmt.Printf("\nEmployee name after change: %s", e.name)

	fmt.Printf("\n\nEmployee age before change: %d", e.age)
	(&e).changeAge(51)
	fmt.Printf("\nEmployee age after change: %d\n", e.age)

	ma := myInt(5)
	mb := myInt(8)
	mc := mb.add(ma)
	fmt.Println(mc)

	mystr := myString("sharwenluo adde deedoiu")
	var inf VowelsFinder
	inf = mystr
	vowels := inf.FindVowels()
	fmt.Println(vowels)

	fmt.Println(mystr.FindVowels())

	// zero interface to find type or assert
	findType(56)
	findType("sharwenluo")
	findType(2.13)
	findType(uint64(54))

	var ch chan int
	ch = make(chan int)
	go writeChannel(ch)
	// for {
	// 	i, ok := <-ch
	// 	if ok == true {
	// 		fmt.Printf("%d ", i)
	// 	}else {
	// 		break
	// 	}
	// }

	for i := range ch {
		fmt.Printf("%d ", i)
	}

	var ch1 = make(chan string)
	var ch2 = make(chan string)
	go server1(ch1)
	go server2(ch2)
	select {
	case val := <-ch1:
		fmt.Println("get serve1", val)
	case val2 := <-ch2:
		fmt.Println("get serve2", val2)
	}

	// nametest := "sharwenluo"
	// nametest1 := ""
	// defer fmt.Println("main def")
	// defer recovery()
	// fullName(&nametest, nil)
	// fullName(&nametest, &nametest1)

	fmt.Println(GetGID())

	ctx := context.Background()
	// ctx1, cancel := context.WithTimeout(ctx, 5*time.Second)
	// fmt.Println(ctx1.Deadline())
	// fmt.Println(time.Now())
	// defer cancel() // 这里不用 cancel 也能做到定时
	// handle(ctx1, 10*time.Second)
	// fmt.Println(time.Now())
	ctx1 := context.WithValue(ctx, "test", "testval")
	v := ctx1.Value("test1")
	fmt.Println(v)

	if v == nil {
		v = ctx1.Value("test1")
		fmt.Println(v)

		val, ok := v.(string)
		fmt.Println(val, ok)
	}

	ctx1 = context.WithValue(ctx1, "test1", "test222")
	fmt.Println(ctx1.Value("test"), ctx1.Value("test1"))

	map11 := map[int]string{
		1:  "sharwen",
		0:  "test",
		-1: "hh",
		2:  "heihei",
	}

	for k, v := range map11 {
		fmt.Println(k, v)
	}

	val, ok := map11[3]
	fmt.Println(ok, val)

	// if ok == true {

	// } else {
	// 	ctx1, cancel := context.WithCancel(ctx)
	// 	wg := NewRoutineGroup()
	// 	wg.RunSafeWithCtxCancel(ctx1, func() {
	// 		time.Sleep(1 * time.Second)
	// 		fmt.Println("ready to cancel")
	// 		cancel()
	// 	})
	// 	wg.RunSafeWithCtxCancel(ctx1, func() {
	// 		fmt.Println("123")
	// 		time.Sleep(10 * time.Second)
	// 	})
	// 	wg.Wait()

	// 	fmt.Println("over")
	// }

	// fmt.Println("over")

	var data Data
	data.Item = 3
	deal1(data)
	fmt.Println(data)

	var testmap map[string]*Employee
	for k, val := range testmap {
		fmt.Println(k, val)
	}

	fmt.Println(testmap)
	fmt.Println(*(&testmap))
	fmt.Println(testmap["1"])

	if *(&testmap) == nil {
		fmt.Println("nil map")
	}

	var testGroup Employee
	fmt.Println(testGroup)

	var str1 string = "1231232"
	fmt.Println(&str1)
	getstring(str1)

	wg := NewRoutineGroup()
	arry := []int{1, 2, 3, 4, 5}
	for i, val := range arry {
		wg.RunSafeWithCtx(ctx, func() {
			var func1 = func(i int, val *int) {
				fmt.Println(i, *val)
			}
			func1(i, &val)
			val = val + 1
		})
	}
	wg.Wait()

	fmt.Println(arry)

	MsgContent := "{\"text\":\"Silakan klik Chat dengan Agen Shopee\",\"queue_category_id\":-1,\"queue_option_id\":0,\"queue_type\":2,\"let_user_choose\":true,\"sf_live_agent\":{\"queue_category_id\":-1,\"queue_option_id\":0}}"
	MsgContent1 := "{\"article_title\":\"Bagaimana cara saya mengklaim pesanan yang hilang atau rusak?\",\"article_content\":\"\u003cp class=\\\"ql-align-justify\\\"\u003eGanti rugi atas kerusakan atau kehilangan barang sepenuhnya akan diproses sesuai kebijakan yang ditetapkan oleh pihak jasa kirim.\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003eBerikut hal yang harus diperhatikan sebelum pengajuan klaim:\u003c/p\u003e\u003col\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eOngkos kirim yang tertera di aplikasi Shopee belum termasuk biaya perlindungan (kecuali untuk jasa kirim GrabExpress, dan GoSend).\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eShopee menyarankan Penjual untuk memberikan perlindungan barang bernominal tinggi atau pesanan yang belum terlindungi senilai harga barang dengan mengaktifkan \u003cu style=\\\"color:rgb(238, 77, 45)\\\"\u003e\u003ca href=\\\"https://seller.shopee.co.id/edu/article/17345\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003eAsuransi Pengiriman Shopee\u003c/a\u003e\u003c/u\u003e.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eShopee memiliki kewenangan dalam menentukan langkah berikutnya untuk pengajuan klaim dan siapa yang harus menanggung biaya ongkos kirim pengembalian barang (jika barang perlu dikembalikan terlebih dahulu).\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eKeputusan yang dibuat oleh Shopee bersifat mutlak dan tidak dapat diganggu gugat.\u003c/li\u003e\u003c/ol\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003ePengajuan klaim atau penggantian tidak berlaku dan akan ditolak apabila:\u003c/p\u003e\u003col\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003ePaket yang dikirim oleh Penjual tidak dikemas atau dibungkus sama sekali.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eProduk yang dikirim termasuk produk yang dilarang atau produk berbahaya*.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003ePaket yang dikirim dengan tipe layanan pengiriman Instant dan Sameday melebihi ukuran maksimal yang berlaku di masing-masing jasa kirim sesuai dengan ketentuan \u003cu style=\\\"color:rgb(238, 77, 45)\\\"\u003e\u003ca href=\\\"https://seller.shopee.co.id/edu/article/16188\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003eOngkos Kirim\u003c/a\u003e\u003c/u\u003e.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eProduk berupa cairan atau pecah belah yang tidak dikemas secara aman dan/atau tidak menggunakan \u003cem\u003ebubble wrap\u003c/em\u003e. Pelajari lebih lanjut mengenai \u003cu style=\\\"color:rgb(238, 77, 45)\\\"\u003e\u003ca href=\\\"https://seller.shopee.co.id/edu/article/18823\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003estandar pengemasan yang berlaku di Shopee\u003c/a\u003e\u003c/u\u003e.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eProduk berupa emas atau barang berharga yang tidak dikemas secara aman dan tidak menggunakan kardus dengan ukuran min. 20x15x10cm (hanya bisa dikirim dengan jasa kirim SPX Express).\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eProduk berupa logam mulia (kecuali emas dengan nilai maksimal Rp4.500.000 untuk jasa kirim GoSend) dan perhiasan untuk jasa kirim GoSend dan GrabExpress.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eProduk berupa cairan \u0026gt;100ml untuk jasa kirim SiCepat.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003ePesanan dikirimkan menggunakan resi pengiriman yang berbeda dengan resi pengiriman yang ada di sistem Shopee maupun mengirimkan barang dengan kurir toko.\u003c/li\u003e\u003c/ol\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003eUntuk mengklaim barang yang rusak/hilang, kakak harus menyiapkan bukti foto/video yang diperlukan untuk membuktikan bahwa kakak memiliki:\u003c/p\u003e\u003col\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003ePesanan berhasil dikirim (Contoh: tanda terima pengiriman, foto paket beserta resi yang menunjukkan alamat penerima).\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eKemasan luar dan dalam pesanan produk yang sesuai dengan pesanan dan tidak rusak (sebelum dikemas).\u003c/li\u003e\u003c/ol\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cspan style=\\\"color:rgba(0, 0, 0, 0.87)\\\"\u003eUntuk mengetahui proses dan waktu yang dibutuhkan saat mengajukan penggantian, pelajari \u003c/span\u003e\u003cu style=\\\"color:rgb(238, 77, 45)\\\"\u003e\u003ca href=\\\"https://shopee.co.id/m/klaim-barang-hilang-rusak\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003ecara klaim barang hilang/rusak\u003c/a\u003e\u003c/u\u003e\u003cspan style=\\\"color:rgba(0, 0, 0, 0.87)\\\"\u003e.\u003c/span\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003ePesanan yang disarankan untuk menggunakan perlindungan jasa kirim:\u003c/p\u003e\u003col\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003ePesanan yang belum terlindungi senilai harga barang.\u003c/li\u003e\u003cli data-list=\\\"ordered\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003ePesanan bernominal tinggi di atas Rp1.000.000 atau bernominal lebih besar dari 10X ongkos kirim.\u003c/li\u003e\u003c/ol\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cblockquote class=\\\"ql-align-justify\\\"\u003e⚠️ \u003cstrong\u003eCatatan\u003c/strong\u003e\u003c/blockquote\u003e\u003col\u003e\u003cli data-list=\\\"bullet\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eUntuk memberikan perlindungan atas kehilangan/kerusakan saat pengiriman, kakak dapat mengaktifkan \u003cu style=\\\"color:rgb(238, 77, 45)\\\"\u003e\u003ca href=\\\"https://seller.shopee.co.id/edu/article/17345\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003eAsuransi Pengiriman Shopee\u003c/a\u003e\u003c/u\u003e.\u003c/li\u003e\u003cli data-list=\\\"bullet\\\" class=\\\"ql-align-justify\\\"\u003e\u003cspan class=\\\"ql-ui\\\"\u003e\u003c/span\u003eUntuk mengetahui nominal penggantian klaim, pelajari \u003cu style=\\\"color:rgb(238, 77, 45)\\\"\u003e\u003ca href=\\\"https://seller.shopee.co.id/edu/article/14230\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003eKebijakan Penggantian Klaim dan Perlindungan dari Jasa Kirim untuk Barang Hilang/Rusak\u003c/a\u003e\u003c/u\u003e.\u003c/li\u003e\u003c/ol\u003e\u003cp class=\\\"ql-align-justify\\\"\u003e\u003cbr /\u003e\u003c/p\u003e\u003cp class=\\\"ql-align-justify\\\"\u003eUntuk informasi lebih lanjut, klik link \u003ca href=\\\"https://seller.shopee.co.id/edu/article/14228\\\" target=\\\"_blank\\\" class=\\\"chatbot-text-link-https\\\"\u003eini\u003c/a\u003e\u003c/p\u003e\"}\n"
	originArticle := &ArticleResponse{}
	if err := json.Unmarshal([]byte(MsgContent), originArticle); err != nil {
		fmt.Printf("err: %s", err.Error())
	} else {
		fmt.Printf("succ")
	}

	originArticle1 := &ArticleResponse{}
	if err := json.Unmarshal([]byte(MsgContent1), originArticle1); err != nil {
		fmt.Printf("err: %s", err.Error())
	} else {
		fmt.Printf("succ")
	}

	fmt.Printf(*originArticle1.ArticleContent, *originArticle1.ArticleTitle)
}
