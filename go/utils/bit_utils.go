package utils

// 返回数字num的二进制情况下，第pos位是0还是1，如果越界则是-1
func GetBit(num int64, pos int) int {
	if pos < 0 || pos >= 64 {
		return -1
	}
	return int((num >> pos) & 1)
}

// 返回根据位数返回对应的数字
func GetNumByBinaryBit(positions []int) int64 {
	var num int64 = 0
	s := NewSet()
	// 去重
	for _, pos := range positions {
		s.Add(pos)
	}
	for _, pos := range s.ToIntList() {
		// 非法位置去除
		if pos < 0 || pos >= 64 {
			continue
		}
		num |= (1 << pos)
	}
	return num
}

// 所有位都可以设置 0 和 1（0-63）, 当成uint64看待为无符号即可。
func NumBinaryBitAssign(num int64, pos int, val int) int64 {
	if pos < 0 || pos >= 64 {
		return num
	}

	if val != 0 && val != 1 {
		return num
	}

	if val == 1 {
		num |= 1 << pos
	} else {
		// 本身是 0 直接跳过
		bitVal := (uint64(num) & uint64(1<<pos)) >> pos
		if bitVal == 1 {
			num ^= 1 << pos
		}
	}

	return num
}

func GetValueByBinaryPos(num int64, highLastBitPos int) (high int64, low int64) {
	if highLastBitPos < 0 || highLastBitPos >= 64 {
		high = num
		low = 0
		return
	}

	var mask uint64 = ^uint64(0)
	mask = mask >> highLastBitPos
	mask = mask << highLastBitPos
	high = num & int64(mask)
	low = num & (^int64(mask))

	return
}
