package main

import (
	"fmt"
	"math"
	"reflect"
	"codedaily/calculate"
)

func init() {
	fmt.Println("init ... main")
}

func test(a int, b int) {
	fmt.Println("a + b = ", a + b);
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

func main () {
	fmt.Println("hello word");

	var age int; // default assined value is 0
	fmt.Println("age is", age);
	age = 18;

	fmt.Println("new age is", age);

	// type inference

	var num = 568;
	fmt.Println("num is", num);

	var str = "hello word 2"
	fmt.Println("string is", str);


	// multiple variables declaration
	var width, height int = 110, 165;
	fmt.Println("width, height are", width, height);
	fmt.Println("width is", width, "height is", height);


	//mutiple variables declaration with inference
	var name, sex = "zhangsan", "male";
	fmt.Println(name + ", "+sex );

	// mutiple varibles declaration with different types

	var (
		car string = "BYD han dynasty"
		year int = 3
		money float64 = 19.8
	);

	fmt.Println("car brand is", car, "used years", year, "speed monry", money);

	//short hand variable declaration
	buildingname, high := "building name", 100.8
	fmt.Println("building name", buildingname, "high", high)


	// math operation
	a, b := 1.6, 2.8
	c := math.Min(a, b)
	fmt.Println("min value of a", a, "and b", b, "is c", c)


	// type
	// bool 
	t := true;
	f := false;
	fmt.Println("go true", t, "go fasle", f);


	// signed integers
	// int8 -128 ~ 127 10^2
	var int8_max int8 = 127;
	var int8_min int8 = -128;
	fmt.Println("int8 min:", int8_min, "int8 max:", int8_max);

	int8_max += 1;
	fmt.Println("int8_max += 1", int8_max);

	// int16 
	// -2^15 ~ 2^15 - 1  -32768 to 32767  量级 3 * 10^5
	var int16_min int16 = -32768;
	var int16_max int16 = 32767
	fmt.Println("int16 min:", int16_min, "int16 max:", int16_max);

	// int32
	// -2^31 ~ 2^31 - 1 	-2147483648 to 2147483647 量级 2 * 10 ^ 10
	var int32_min int32 = -2147483648;
	var int32_max int32 = 2147483647
	fmt.Println("int32 min:", int32_min, "int32 max:", int32_max);

	// int 64
	// 量级 9 * 10 ^ 19
	var int64_min int64 = -9223372036854775808;
	var int64_max int64 = 9223372036854775807
	fmt.Println("int64 min:", int64_min, "int64 max:", int64_max);


	// unsinged intergers
	// 0 ~ 255 2 * 10^2
	var uint8_min uint8 = 0;
	var uint8_max uint8 = 255;
	fmt.Println("uint8 min:", uint8_min, "uint8 max:", uint8_max);

	// uint16
	// 0 ~ 65535 6 * 10^5
	var uint16_min uint16 = 0;
	var uint16_max uint16 = 65535;  
	fmt.Println("uint16 min:", uint16_min, "uint16 max:", uint16_max);

	// uint32
	// 0 ~ 4294967295 4 * 10^10 
	var uint32_min uint32 = 0;
	var uint32_max uint32 = 4294967295;
	
	fmt.Println("uint32 min:", uint32_min, "uint32 max:", uint32_max);

	// uint64
	// 0 ~ 18446744073709551615 18 * 10 ^ 19 1 * 10 ^ 20
	var uint64_min uint64 = 0;
	var uint64_max uint64 = 18446744073709551615;
	fmt.Println("uint64 min:", uint64_min, "uint64 max:", uint64_max);


	// floatting type float32 float64
	var float32_num float32 = 3.1415926;
	var float64_num	float64	= 3.141592654;
	fmt.Println("float32 number is", float32_num,"\n","float64 number is", float64_num )
	// fmt.Println("type float32_num is float32_num %T", float32_num) not support any more ?
	fmt.Println("type float32_num is", reflect.TypeOf(float32_num), "type float64_num is", reflect.TypeOf(float64_num))


	// complext type
	c1 := 6 + 7i;
	c2 := 7 + 8i;
	fmt.Println("c1 ", c1, " + c2", c2, "=", c1 + c2);

	// uint8 as byte
	// int32 as rune


	// string
	var surname string = "luo";
	var secondname string = "shengwen";
	fmt.Println("name is", surname + " " + secondname);

	// type convert, no implict convert in go, we should use type convert explict
	var num1 rune  = 568;
	var float_num float64 = 3.141592654;
	//var ans = num1 + float_num // ./helloword.go:144:12: invalid operation: num1 + float_num (mismatched types rune and float64)
	var ans = float64(num1) + float_num;
	fmt.Println("ans is", ans);

	name = "luoshengwen";
	fmt.Println("name is", name);

	// const variables fix value
	const pi float64 = 3.141592654;
	fmt.Println("pi is", pi);

	// declareing a group of constants The value of a constant should be known at compile time
	const (
		name1 = "sharwen"
		age1 = 29
		sex1 = "male"
	)

	fmt.Println("name is", name1, "age", age1, "sex is", sex1);


	test(1, 2);


	area, perimeter := rectProps(1.5, 2);
	fmt.Println("area, perimeter:", area, perimeter);


	area1, perimeter1 := rectProps1(1.5, 2);
	fmt.Println("area1, perimeter1:", area1, perimeter1);

	// _ is known as the blank identifier， the _ variable will be discard
	area2, _ := rectProps1(3, 1.5)
	fmt.Println("area is ", area2);


	// test for add package

	sum := calculate.Addfunc3(1, 2, 4);
	fmt.Println("sum is", sum);
	calculate.Test()

	// if statement syntax
	odd, even := 1,2
	if odd % 2 == 1 {
		fmt.Println("odd", odd, "is an odd number");
	} else {
		fmt.Println("odd", odd, "is an even number");
	}
	
	if even % 2 == 0 {
		fmt.Println("even", even, "is an even number");
	} else {
		fmt.Println("even", odd, "is an odd number");
	}

	// for statement
	for i := 1; i <= 10; i++ {
		if(i > 5) {
			break;
		}
		fmt.Printf("%d ", i);
	}
	fmt.Println("\nline after for loop")


	// swith
	switch k := 3; k {
	case 1:
		fmt.Println("1");
	case 2:
		fmt.Println("2");
	case 3, 4, 5: // mutiple expressions
		fmt.Println("3");
	default:
		fmt.Println("other");
	}

	// switch expressionless swith
	k := 68
	switch {
	case k < 0:
		fmt.Println("less than zero")
	case k >=0 && k <= 100:
		fmt.Println("val between 0 - 100")
		fallthrough // next case will be execute although condition is false
	case k > 100 && k <= 1000:
		fmt.Println("large than 100 less equal than 1000")
	default:
		fmt.Println("large than 1000")
	}


	// array and slice
	arrnum := []int {1,2,3} // arrnum is reference of a new array
	for i, _ := range arrnum {
		arrnum[i]++;
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
	
}