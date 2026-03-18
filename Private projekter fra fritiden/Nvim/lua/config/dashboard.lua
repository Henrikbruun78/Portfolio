vim.api.nvim_create_autocmd("VimEnter", {
  callback = function()
    if vim.fn.argc() > 0 then
      return
    end

    local header = {
      " _   _                 _             ",
      "| \\ | | _____   _(_)_ __ ___        ",
      "|  \\| |/ _ \\ \\ / / | '_ ` _ \\       ",
      "| |\\  |  __/\\ V /| | | | | | |      ",
      "|_| \\_|\\___| \\_/ |_|_| |_| |_|      ",
      "",
      "       Learn the editor itself       ",
    }

    local cheatsheet = {
      "",
      "Files",
      "  :Explore       open netrw",
      "  <leader>e      open netrw",
      "  -              go up a directory",
      "  Enter          open file or folder",
      "  %              create a new file",
      "",
      "Movement",
      "  h j k l        move left/down/up/right",
      "  gg / G         top / bottom of file",
      "  w / b          next / previous word",
      "",
      "Editing",
      "  i              insert before cursor",
      "  Esc            leave insert mode",
      "  x              delete character",
      "  u / Ctrl-r     undo / redo",
      "",
      "Saving",
      "  :w             save",
      "  :q             quit",
      "  :wq            save and quit",
      "  :q!            quit without saving",
      "",
      "Help",
      "  :help          open help",
      "  :Tutor         start the tutorial",
    }

    local width = vim.api.nvim_get_option_value("columns", {})
    local lines = {}

    local function center(line)
      local pad = math.max(0, math.floor((width - #line) / 2))
      return string.rep(" ", pad) .. line
    end

    for _, line in ipairs(header) do
      table.insert(lines, center(line))
    end

    table.insert(lines, "")

    for _, line in ipairs(cheatsheet) do
      table.insert(lines, center(line))
    end

    vim.cmd("enew")
    vim.bo.buftype = "nofile"
    vim.bo.bufhidden = "wipe"
    vim.bo.swapfile = false
    vim.bo.modifiable = true
    vim.bo.filetype = "starter"

    vim.api.nvim_buf_set_lines(0, 0, -1, false, lines)

    vim.bo.modifiable = false
    vim.opt_local.number = false
    vim.opt_local.relativenumber = false
    vim.opt_local.cursorline = false
    vim.opt_local.signcolumn = "no"

    vim.keymap.set("n", "q", "<cmd>qa<cr>", { buffer = true, silent = true })
    vim.keymap.set("n", "<CR>", "<cmd>Explore<cr>", { buffer = true, silent = true })

    vim.api.nvim_win_set_cursor(0, { 1, 0 })
  end,
})
