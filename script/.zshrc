export CLICOLOR=1
export LSCOLORS=CxfxcxdxbxegedabagGxGx
autoload -U colors && colors
PROMPT="%{$fg_bold[cyan]%}%n%{$reset_color%}@%{$fg_bold[cyan]%}%m %{$fg_bold[green]%}%1~ %{$reset_color%}%#"


alias ll="ls -all"
