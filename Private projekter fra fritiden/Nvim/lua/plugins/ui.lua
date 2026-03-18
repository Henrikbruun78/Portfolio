return {
  {
    "Mofiqul/vscode.nvim",
    priority = 1000,
    config = function()
      local function apply_vscode_overrides()
        local highlights = {
          Normal = { fg = "#D4D4D4", bg = "#1E1E1E" },
          LineNr = { fg = "#858585" },
          CursorLineNr = { fg = "#C6C6C6", bold = true },
          CursorLine = { bg = "#252526" },
          SignColumn = { bg = "#1E1E1E" },
          ColorColumn = { bg = "#2A2D2E" },
          Comment = { fg = "#6A9955", italic = true },
          Constant = { fg = "#4FC1FF" },
          String = { fg = "#CE9178" },
          Character = { fg = "#CE9178" },
          Number = { fg = "#B5CEA8" },
          Boolean = { fg = "#569CD6" },
          Float = { fg = "#B5CEA8" },
          Identifier = { fg = "#9CDCFE" },
          Function = { fg = "#DCDCAA" },
          Statement = { fg = "#C586C0" },
          Conditional = { fg = "#C586C0" },
          Repeat = { fg = "#C586C0" },
          Label = { fg = "#C8C8C8" },
          Operator = { fg = "#D4D4D4" },
          Keyword = { fg = "#C586C0" },
          Exception = { fg = "#C586C0" },
          PreProc = { fg = "#C586C0" },
          Include = { fg = "#C586C0" },
          Define = { fg = "#C586C0" },
          Macro = { fg = "#C586C0" },
          PreCondit = { fg = "#C586C0" },
          Type = { fg = "#4EC9B0" },
          StorageClass = { fg = "#569CD6" },
          Structure = { fg = "#569CD6" },
          Typedef = { fg = "#569CD6" },
          Special = { fg = "#D7BA7D" },
          Delimiter = { fg = "#D4D4D4" },
          SpecialComment = { fg = "#6A9955" },
          Underlined = { fg = "#569CD6", underline = true },
          DiagnosticUnderlineError = { undercurl = true, sp = "#F44747" },
          DiagnosticUnderlineWarn = { undercurl = true, sp = "#FF8800" },
          cInclude = { fg = "#C586C0" },
          cIncluded = { fg = "#CE9178" },
          cDefine = { fg = "#C586C0" },
          cPreCondit = { fg = "#C586C0" },
          cStorageClass = { fg = "#569CD6" },
          cType = { fg = "#569CD6" },
          cTypedef = { fg = "#569CD6" },
          cStructure = { fg = "#569CD6" },
          cConstant = { fg = "#4FC1FF" },
          cString = { fg = "#CE9178" },
          cCppString = { fg = "#CE9178" },
          cSpecial = { fg = "#D7BA7D" },
          ["@variable"] = { fg = "#9CDCFE" },
          ["@variable.parameter"] = { fg = "#9CDCFE" },
          ["@variable.member"] = { fg = "#9CDCFE" },
          ["@property"] = { fg = "#9CDCFE" },
          ["@function"] = { fg = "#DCDCAA" },
          ["@function.call"] = { fg = "#DCDCAA" },
          ["@type"] = { fg = "#4EC9B0" },
          ["@type.builtin"] = { fg = "#569CD6" },
          ["@keyword"] = { fg = "#C586C0" },
          ["@keyword.import"] = { fg = "#C586C0" },
          ["@keyword.directive"] = { fg = "#C586C0" },
          ["@keyword.directive.define"] = { fg = "#C586C0" },
          ["@string"] = { fg = "#CE9178" },
          ["@string.escape"] = { fg = "#D7BA7D" },
          ["@number"] = { fg = "#B5CEA8" },
          ["@operator"] = { fg = "#D4D4D4" },
          ["@punctuation.delimiter"] = { fg = "#D4D4D4" },
          ["@punctuation.bracket"] = { fg = "#FFD700" },
          ["@lsp.type.variable"] = { fg = "#9CDCFE" },
          ["@lsp.type.parameter"] = { fg = "#9CDCFE" },
          ["@lsp.type.property"] = { fg = "#9CDCFE" },
          ["@lsp.type.function"] = { fg = "#DCDCAA" },
          ["@lsp.type.method"] = { fg = "#DCDCAA" },
          ["@lsp.type.type"] = { fg = "#4EC9B0" },
          ["@lsp.type.typeParameter"] = { fg = "#4EC9B0" },
          ["@lsp.type.macro"] = { fg = "#C586C0" },
          ["@lsp.type.enumMember"] = { fg = "#4FC1FF" },
        }

        for group, spec in pairs(highlights) do
          vim.api.nvim_set_hl(0, group, spec)
        end
      end

      require("vscode").setup({
        transparent = false,
        italic_comments = true,
        underline_links = true,
        disable_nvimtree_bg = true,
        group_overrides = {},
      })
      vim.cmd.colorscheme("vscode")
      apply_vscode_overrides()

      vim.api.nvim_create_autocmd("ColorScheme", {
        pattern = "vscode",
        callback = apply_vscode_overrides,
      })
    end,
  },
  {
    "nvim-tree/nvim-web-devicons",
    lazy = true,
  },
  {
    "nvim-telescope/telescope.nvim",
    cmd = "Telescope",
    dependencies = {
      "nvim-lua/plenary.nvim",
      "nvim-tree/nvim-web-devicons",
    },
    keys = {
      { "<leader>ff", "<cmd>Telescope find_files<cr>", desc = "Find files" },
      { "<leader>fg", "<cmd>Telescope live_grep<cr>", desc = "Live grep" },
      { "<leader>fb", "<cmd>Telescope buffers<cr>", desc = "Find buffers" },
      { "<leader>fh", "<cmd>Telescope help_tags<cr>", desc = "Help tags" },
    },
    config = function()
      local telescope = require("telescope")

      telescope.setup({
        defaults = {
          layout_strategy = "horizontal",
          layout_config = {
            prompt_position = "top",
            preview_width = 0.55,
          },
          sorting_strategy = "ascending",
          winblend = 0,
          prompt_prefix = "  ",
          selection_caret = "  ",
          path_display = { "smart" },
        },
        pickers = {
          find_files = {
            hidden = true,
          },
        },
      })
    end,
  },
  {
    "nvim-lualine/lualine.nvim",
    event = "VeryLazy",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function()
      require("lualine").setup({
        options = {
          theme = "vscode",
          globalstatus = true,
          component_separators = { left = "|", right = "|" },
          section_separators = { left = "", right = "" },
        },
      })
    end,
  },
  {
    "akinsho/bufferline.nvim",
    version = "*",
    event = "VeryLazy",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function()
      require("bufferline").setup({
        options = {
          diagnostics = "nvim_lsp",
          separator_style = "slant",
          always_show_bufferline = true,
          show_buffer_close_icons = false,
        },
      })

      vim.keymap.set("n", "<S-h>", "<cmd>BufferLineCyclePrev<cr>", { desc = "Previous buffer" })
      vim.keymap.set("n", "<S-l>", "<cmd>BufferLineCycleNext<cr>", { desc = "Next buffer" })
    end,
  },
  {
    "lukas-reineke/indent-blankline.nvim",
    main = "ibl",
    event = { "BufReadPre", "BufNewFile" },
    config = function()
      require("ibl").setup({
        indent = {
          char = "│",
        },
        scope = {
          enabled = false,
        },
      })
    end,
  },
  {
    "lewis6991/gitsigns.nvim",
    event = { "BufReadPre", "BufNewFile" },
    config = function()
      require("gitsigns").setup()
    end,
  },
}
