" Simple and nomap vim configuration

"=======> For GUI

colorscheme gruvbox
set background=light
autocmd VimEnter * Lexplore!


"========> For Search

"Set to auto read when a file is changed from the outside
set autoread

" Turn on the Wild menu
set wildmenu

" A buffer becomes hidden when it is abandoned
set hid

" Ignore case when searching
set ignorecase

" When searching try to be smart about cases 
set smartcase

" Highlight search results
set hlsearch

" Makes search act like search in modern browsers
set incsearch


" Show matching brackets when text indicator is over them
set showmatch 

" Enable syntax highlighting
syntax enable 



" ========> Files, backups and undo

" Turn backup off, since most stuff is in SVN, git et.c anyway...
set nobackup
set nowb
set noswapfile

" ========> Text, tab and indent related

" Use spaces instead of tabs
set expandtab

" Be smart when using tabs ;)
set smarttab

" 1 tab == 4 spaces
set shiftwidth=4
set tabstop=4

" Linebreak on 500 characters
set lbr
set tw=500

set ai "Auto indent
set si "Smart indent
set wrap "Wrap lines

" ======> Fast editing and reloading of vimrc configs
autocmd! bufwritepost ~/.vim_runtime/my_configs.vim source ~/.vim_runtime/my_configs.vim

" ======> Turn persistent undo on
try
    set undodir=~/.vim/temp_dirs/undodir
    set undofile
catch
endtry

"=======> Omni complete functions
autocmd FileType css set omnifunc=csscomplete#CompleteCSS






