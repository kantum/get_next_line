let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/work/gnl
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 get_next_line.c
badd +1 get_next_line.h
badd +1 main.c
badd +1 term://.//46268:zsh
badd +0 libft/includes/libft.h
badd +0 man://read(2)
argglobal
silent! argdel *
edit libft/includes/libft.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
3wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
exe '1resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 1resize ' . ((&columns * 91 + 182) / 364)
exe '2resize ' . ((&lines * 41 + 42) / 84)
exe 'vert 2resize ' . ((&columns * 91 + 182) / 364)
exe 'vert 3resize ' . ((&columns * 90 + 182) / 364)
exe 'vert 4resize ' . ((&columns * 90 + 182) / 364)
exe '5resize ' . ((&lines * 41 + 42) / 84)
exe 'vert 5resize ' . ((&columns * 90 + 182) / 364)
exe '6resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 6resize ' . ((&columns * 90 + 182) / 364)
argglobal
enew
file man://read(2)
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
wincmd w
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
if bufexists('get_next_line.c') | buffer get_next_line.c | else | edit get_next_line.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 41) / 82)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
if bufexists('get_next_line.h') | buffer get_next_line.h | else | edit get_next_line.h | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 41) / 82)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
if bufexists('term://.//46268:zsh') | buffer term://.//46268:zsh | else | edit term://.//46268:zsh | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 14 - ((13 * winheight(0) + 20) / 41)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
14
normal! 024|
wincmd w
argglobal
if bufexists('main.c') | buffer main.c | else | edit main.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
5wincmd w
exe '1resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 1resize ' . ((&columns * 91 + 182) / 364)
exe '2resize ' . ((&lines * 41 + 42) / 84)
exe 'vert 2resize ' . ((&columns * 91 + 182) / 364)
exe 'vert 3resize ' . ((&columns * 90 + 182) / 364)
exe 'vert 4resize ' . ((&columns * 90 + 182) / 364)
exe '5resize ' . ((&lines * 41 + 42) / 84)
exe 'vert 5resize ' . ((&columns * 90 + 182) / 364)
exe '6resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 6resize ' . ((&columns * 90 + 182) / 364)
tabnext 1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
