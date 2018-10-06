" sdothum - 2016 (c) wtfpl

" Core
" ▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂

  " Primitive ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " .................................................................... Setup

      if exists("g:loaded_core")
        finish
      endif
      let g:loaded_core = 1
      let s:save_cpo = &cpo
      set cpo&vim

      let g:ruler     = 0                   " colorcolumn mode
      let g:repo      = $HOME . '/stow/'
      let g:wraplight = 1                   " highlight linewrap (0) off (1) on

      augroup core
        autocmd!
      augroup END

  " System ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " .............................................................. Config file

      " when updates won't break the current vim session!
      command! Vimrc call core#Vimrc()

    " ............................................................ Open terminal

      " open shell session in buffer directory
      command! Term silent call system('term "vimterm" STACK')

      nnoremap <silent><C-t> :Term<CR>
      inoremap <silent><C-t> <C-o>:Term<CR>

    " ............................................................... Dictionary

      " lookup word under cursor
      " nnoremap <silent><C-k> :silent call system('term "vimterm" STACK SHELL "dict <C-r><C-w> \| less"')<CR>
      " inoremap <silent><C-k> <C-o>:silent call system('term "vimterm" STACK SHELL "dict <C-r><C-w> \| less"')<CR>

    " ............................................................... Print file

      command! Hardcopy silent call core#Hardcopy()<CR>:echo 'Printing..'

    " .................................................................... Debug

      nnoremap <silent><F10> :let g:trace = g:trace == 0 ? 1 : 0<CR>

  " Keyboard layout ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " ......................................................... Colemak-shift-dh

      " environment variable
      if $COLEMAK > ''
        call core#Colemak()
      endif

  " GUI ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " ................................................................... Column

      nmap <silent><Bar>           :call core#ToggleColumn()<CR>
      nmap <silent><S-F8>          :call core#ToggleColumnWrap()<CR>
      imap <silent><S-F8>          <C-o>:call core#ToggleColumnWrap()<CR>

  " Text ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " ......................................................... Strip whitespace
    
      nmap <silent><F5>            :call core#StripTrailingWhitespaces()<CR>
      vmap <silent><F5>            :<C-u>call core#StripTrailingWhitespaces()<CR>

      " pre-write formatting
      " autocmd buffer BufWritePre * call core#StripTrailingWhitespaces()
      " " focus oriented formatting
      " autocmd buffer BufLeave    * call core#StripTrailingWhitespaces()
      " autocmd buffer FocusLost   * call core#StripTrailingWhitespaces()

    " .......................................................... Code block text

      " markup wiki code blocks
      nnoremap <silent><leader>`  V:call core#CodeBlock()<CR>
      vmap     <silent><leader>`  :call core#CodeBlock()<CR>

    " .......................................................... CSS block align

      nnoremap <silent><S-F5>     :call core#CssBlockAlign()<CR>

  " Filetype ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁

    " ............................................................... Modifiable

      " check filetype on open
      autocmd core BufNewFile,BufRead * call core#CheckFiletype()

    " ................................................................... E-mail

      " position cursor for email reply or new message, see .sup/config.yaml and bin/dcompose
      autocmd core Filetype mail call core#ComposeMail()

      let &cpo = s:save_cpo
      unlet s:save_cpo

" core.vim
