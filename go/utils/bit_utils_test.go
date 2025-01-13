package utils

import "testing"

func TestBit(t *testing.T) {
	num := int64(25) // 25 = 16 + 8 + 1

	bits := make([]int, 0)
	result0 := GetBit(num, 0)
	result1 := GetBit(num, 1)
	result2 := GetBit(num, 2)
	result3 := GetBit(num, 3)
	result4 := GetBit(num, 4)

	bits = append(bits, result0, result1, result2, result3, result4)
	positions := make([]int, 0)

	for pos, bit := range bits {
		if bit != 0 {
			positions = append(positions, pos)
		}
		if pos == 0 && bit == 0 {
			t.Errorf("positions %d, expected 1, got %d", pos, bit)
		}
		if pos == 3 && bit == 0 {
			t.Errorf("positions %d, expected 1, got %d", pos, bit)
		}
		if pos == 4 && bit == 0 {
			t.Errorf("positions %d, expected 1, got %d", pos, bit)
		}
	}

	numGet := GetNumByBinaryBit(positions)
	if numGet != num {
		t.Errorf("Expected: %d, but get:%d", num, numGet)
	}

	t.Logf("Success, positions: %v, numGet: %d", positions, numGet)
}

func checkBitStatus(t *testing.T, num int64, set *Set) {
	for i := 0; i < 64; i++ {
		ok := set.Has(i)
		if ok {
			if GetBit(num, i) == 1 {
				continue
			}
			t.Errorf("except pos %d: 1 but get 0", i)
		} else {
			if GetBit(num, i) == 0 {
				continue
			}
			t.Errorf("except pos %d: 0 but get 1", i)
		}
	}
}

func TestNumBinaryBitSet(t *testing.T) {
	var num int64 = 0
	// 设置第0 位为 1
	num = NumBinaryBitAssign(num, 0, 1)
	if num != 1 {
		t.Errorf("expect get 1, but got %d", num)
	}

	set := NewSet()
	for i := 0; i < 64; i++ {
		num = NumBinaryBitAssign(num, i, 1)
		set.Add(i)
		checkBitStatus(t, num, set)
	}

	for i := 63; i >= 0; i-- {
		num = NumBinaryBitAssign(num, i, 0)
		set.Remove(i)
		checkBitStatus(t, num, set)
	}
}

func TestNumBinaryBitSet1(t *testing.T) {
	var num int64 = 0
	num = NumBinaryBitAssign(num, 1, 0)
	if num != 0 {
		t.Errorf("expect get %d, but got %d", 0, num)
	}
	num = NumBinaryBitAssign(num, 1, 1)
	if num != 2 {
		t.Errorf("expect get %d, but got %d", 2, num)
	}

	num = NumBinaryBitAssign(num, 1, 0)
	if num != 0 {
		t.Errorf("expect get %d, but got %d", 0, num)
	}
}

func TestGetBinaryNumByPos(t *testing.T) {
	type caseItem struct {
		num            int64
		high           int64
		low            int64
		highLastBitPos int
	}

	testCases := []caseItem{
		{num: 2, high: 2, low: 0, highLastBitPos: 0},
		{num: 2, high: 2, low: 0, highLastBitPos: 1},
		{num: 2, high: 0, low: 2, highLastBitPos: 2},
		{num: 3, high: 3, low: 0, highLastBitPos: 0},
		{num: 3, high: 2, low: 1, highLastBitPos: 1},
		{num: 3, high: 0, low: 3, highLastBitPos: 2},
		{num: ^0, high: -int64(1 << 62), low: int64((^uint64(0)) >> 2), highLastBitPos: 62},
		{num: ^0, high: -9223372036854775808, low: int64((^uint64(0)) >> 1), highLastBitPos: 63},
	}

	for i, testCase := range testCases {
		high, low := GetValueByBinaryPos(testCase.num, testCase.highLastBitPos)
		if high != testCase.high {
			t.Errorf("case %d expect get %d but got %d", i, testCase.high, high)
		}
		if low != testCase.low {
			t.Errorf("case %d expect get %d but got %d", i, testCase.low, low)
		}
	}
}

func TestBitGet(t *testing.T) {
	var num int64 = -1
	for i := 0; i < 64; i++ {
		println(GetBit(num, i))
	}
}
