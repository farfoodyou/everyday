#!/usr/local/bin/lua
--[[
    this is lua tutorial.
]]--

-- 1. numbers and strings
num1 = 1
num2 = 2.3
print(num1 + num2)

string1 = "Lua"
string2 = 'baidu.com'
string3 = [["Lua 教程ing\n]]
print("\"字符串 1 是\"",string1)
print("字符串 2 是",string2)
print("字符串 3 是",string3)

-- 2. loops
times = 3
while( times > 0 )
do
    times = times - 1;
    print("循环还将执行" .. times .."次");
end
for i = 3,1,-1 
do 
   print(i) 
end

-- 3. arrays and tables
array = {"Lua", "Tutorial"}
for i= 0, 2 do
   print(array[i])
end

-- 4. functions
function max(num1, num2)
    if (num1 > num2) then
       result = num1;
    else
       result = num2;
    end
    return result; 
end
print(max(num1,num2))

myprint = function(param)
    return "这是打印函数 - ## sum is  " .. param .. " ##"
end
 
function add(num1,num2,functionPrint)
    result = num1 + num2
    -- 调用传递的函数参数
    return functionPrint(result)
end
myprint(10)
    -- myprint 函数作为参数传递
print(add(2,3,myprint))

-- 5. objects
    -- Meta class
Rectangle = {area = 0, length = 0, breadth = 0}
    -- 派生类的方法 new
function Rectangle:new (o,length,breadth)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  self.length = length or 0
  self.breadth = breadth or 0
  self.area = length*breadth;
  return o
end
    -- 派生类的方法 printArea
function Rectangle:printArea ()
  print("矩形面积为 ",self.area)
end
r = Rectangle:new(nil,10,20)
r:printArea()
