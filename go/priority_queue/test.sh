#!/bin/sh

go test -v -cover -count=1 -coverprofile=c.out .

# https://stackoverflow.com/questions/73432741/why-does-count-1-ignores-caching-in-go-tests for count=1