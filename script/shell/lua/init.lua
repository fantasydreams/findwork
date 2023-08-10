-- #hammerspoon 的快捷键脚本
-- 使用【Option+Q】在不同屏幕之间移动鼠标
hs.hotkey.bind({'option'}, 'Q', function()
    local screen = hs.mouse.getCurrentScreen()
    local nextScreen = screen:next()
    local rect = nextScreen:fullFrame()
    local center = hs.geometry.rectMidPoint(rect)
    hs.mouse.absolutePosition(center)
end)

-- 使用[Option+F] 在不同屏幕之间切换并点击鼠标左键
hs.hotkey.bind({'option'}, 'D', function()
    local screen = hs.mouse.getCurrentScreen()
    local nextScreen = screen:next()
    local rect = nextScreen:fullFrame()
    local center = hs.geometry.rectMidPoint(rect)
    hs.mouse.absolutePosition(center)
    hs.eventtap.leftClick(center)
end) 

-- Option + C 触发鼠标左键事件
hs.hotkey.bind({'option'}, 'H', function()
    local point = hs.mouse.getRelativePosition()
    hs.eventtap.leftClick(point)
end)

-- 使用【Option+W】在不同屏幕之间移动窗口
hs.hotkey.bind({'option'}, 'W', function()
    -- get the focused window
    local win = hs.window.focusedWindow()
    -- get the screen where the focused window is displayed, a.k.a. current screen
    local screen = win:screen()
    -- compute the unitRect of the focused window relative to the current screen
    -- and move the window to the next screen setting the same unitRect 
    win:move(win:frame():toUnitRect(screen:frame()), screen:next(), true, 0)
end)