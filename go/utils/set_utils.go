package utils

type Set struct {
	m map[interface{}]struct{}
}

func NewSet() *Set {
	return &Set{
		m: make(map[interface{}]struct{}),
	}
}

func (s *Set) Add(k interface{}) {
	s.m[k] = struct{}{}
}

func (s *Set) Remove(k interface{}) {
	delete(s.m, k)
}

func (s *Set) Has(k interface{}) bool {
	_, ok := s.m[k]
	return ok
}

func (s *Set) Len() int {
	return len(s.m)
}

func (s *Set) Clear() {
	s.m = make(map[interface{}]struct{})
}

func (s *Set) ToStringList() []string {
	var list []string
	for k := range s.m {
		value, ok := k.(string)
		if !ok {
			continue
		}
		list = append(list, value)
	}
	return list
}

func (s *Set) ToUintList() []uint {
	var list []uint
	for k := range s.m {
		value, ok := k.(uint)
		if !ok {
			continue
		}
		list = append(list, value)
	}
	return list
}

func (s *Set) ToIntList() []int {
	var list []int
	for k := range s.m {
		value, ok := k.(int)
		if !ok {
			continue
		}
		list = append(list, value)
	}
	return list
}

func StringSliceToSet(slice []string) *Set {
	s := NewSet()
	for _, v := range slice {
		s.Add(v)
	}
	return s
}
