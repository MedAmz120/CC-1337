/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:06:32 by moamzil           #+#    #+#             */
/*   Updated: 2023/12/08 02:39:08 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define DOUBLE_Q 34
# define SINGLE_Q 39
# define CMD_NOT_FOUND 404
# define BACK_SLASH 92
# define FILE_NOT_FOUND 500
# define READLINE_PROM	"minishell$ "

/* <-------- STD LIBRARYS --------> */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
/* <---------------------------------> */

/* <-------- LOCAL LIBRARYS --------> */
# include "../src/libft/libft.h"
# include "parsing.h"
/* <---------------------------------> */

typedef struct s_cmds {
	char			*cmd;
	char			**args;
	char			**new_args;
	int				is_pipe;
	char			*file;
	t_redir			*red;
	struct s_cmds	*next;
	struct s_cmds	*prev;
}	t_cmds;

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_tools {
	char	**paths;
	char	**envp;
	char	**env_new;
	char	*rline;
	char	*pwd;
	char	*old_pwd;
	int		error;
	int		pipes;
	int		exit_status;
	char	*env_name;
	int		in_double_quotes;
	int		i;
	int		x;
	int		j;
	int		flag;
	char	*arg_tmp;
	char	*arg_tmp_2;
	char	*arg_tmp_3;
	t_env	*env_list;
	t_lexer	*lexer_list;
	t_cmds	*s_cmds;
	int		fd[2];
	int		fd_prev[2];
	int		c;
}	t_tools;

/* --------------------------------------- */
/* ---------- MAIN	FUNCTIONS ---------- */
void		ft_parsing(t_tools *t, char **envp, int fd0, int fd1);
int			check_empty_cmd(t_tools *t);
void		quit_program(t_tools *t, int S_F);
// ---------------------------------------

// ---------- UTILS		FUNCTIO ----------
char		**realloc_2d(char **tab, char *str, t_tools *t);
size_t		ft_2dlen(char **tab);
size_t		ft_strllen(char *str, int start, char end);
char		**ft_2dup(char **tab);
void		ft_clean_spaces(t_tools *t);
int			find_close_quotes(char *line, int pos, int *d_s, int c);
int			count_double_quotes(char *line);
void		find_env_path(t_tools *t);
void		find_pwd(t_tools *t);
void		ft_initialize(t_tools *t);
t_tokens	check_opr(int c);
int			skip_double_single(char *str, int i);
int			is_whitespace(char c);
int			skip_white_spaces(char *str, int pos);
// ---------------------------------------

// ---------- TOKENIZER FUNCTIO ----------
int			tokenize(char *str, int i, t_lexer **lexer_list);
int			read_words(int i, char *str, t_lexer **lexer_list);
int			ft_token(t_tools *t);
int			handle_quotes(int i, char *str, char del);
void		ft_lexeradd_back(t_lexer **lst, t_lexer *new);
t_lexer		*ft_lexernew(char *str, int token);
int			add_node(char *str, t_tokens token, t_lexer **lexer_list);
// ---------------------------------------

// ---------- PARSER  FUNCTIONS ----------
int			init_key(char *src, char *dest);
void		link_list(t_env *env);
t_env		*ft_init_env_list(int n, t_tools *t);
void		ft_env_tolist(t_tools *t);
t_cmds		*ft_parser(t_tools *t);
void		handle_herdoc(t_redir *red, char *arg, t_tools *t);
void		ft_redirections(t_cmds *cmd, t_tokens opr, char *arg, t_tools *t);
t_cmds		*order_cmds(t_lexer *lexer, t_tools *t);
void		link_redir_list(t_redir **head, t_redir *temp);
t_redir		*add_redirection_node(t_tokens opr, char *arg);
t_cmds		*init_cmd(t_lexer *lexer, t_tools *t);
void		link_cmds_list(t_cmds **head, t_cmds *temp);
int			double_check_errors(t_lexer *lexer, t_tools *t);
int			ft_check_pipes(t_tools *t, t_tokens opr);
void		ft_lexerdelone(t_lexer **lst, int key);
t_lexer		*ft_lexerclear_one(t_lexer **lst);
void		ft_lexerdel_first(t_lexer **lst);
int			pipes_counter(t_lexer *lexer_List);
void		fill_args_nr(t_cmds *temp, t_lexer *lexer, t_tools *t);
void		initialize_command(t_lexer *lexer, t_tools *t, t_cmds *temp);
size_t		ft_strlen_skip_v2(char *str);
// ---------------------------------------

// ---------- EXPAND  FUNCTIONS ----------
void		copy_env(char *res, char *str, char *env, t_tools *t);
void		ft_expand_in(char *str, char *res, char *env, t_tools *t);
char		*ft_append_env(char *str, char *env, int env_len, t_tools *t);
char		*ft_expandit(char *str, t_tools *t);
int			get_env_pos(char *str, t_tools *t);
char		*get_env_value(char *str);
char		*ft_envcpy(char *str, int i, t_tools *t);
char		*remove_double_quotes(char *str, t_tools *t);
int			assign_single(char *str, int i, t_tools *t);
int			assign_double(char *str, int i);
int			assign_random(char *str, int i);
void		quotes_backslash(char *str, t_tools *t, char *res);
size_t		ft_strlen_skip(char *str, char c);

// ---------------------------------------

// ---------- ERROR  FUNCTTIONS ----------
void		ft_error_parser_dblopr(t_tools *t, t_tokens opr);
void		ft_error(int error_code, t_tools *t);
// ---------------------------------------

// ---------- FREE   FUNCTTIONS ----------
void		free_node(t_lexer *lexer_list);
void		free_2darr(char **tab, t_tools *t);
void		free_tools_struct(t_tools *t);
void		free_reds_nodes(t_redir *red, t_tools *t);
void		free_cmds_nodes(t_cmds *cmds, t_tools *t);
void		free_env_list(t_env *env);
void		re_init(t_tools *t);
// ---------------------------------------

int			execute(t_cmds *cmd, t_tools *t);
int			ft_strcmp(char *s1, char *s2);
int			mystrcmp(const char *s1, const char *s2);
void		ft_cd(char *path, t_tools *t);
void		echo(char **args);
void		pwd(void);
int			check_export(char *str);
int			ft_strclen(char *str, char c);
void		print_export(t_tools *t);
void		add_node_to_env_list(t_env **env_list, char *key, char *value);
void		export(t_tools *t, t_cmds *cmd);
void		ft_list_remove_if(t_env **env_list, char *key_to_unset);
void		unset(t_tools *t, t_cmds *cmd);
void		free_list(t_env *env_list);
void		env(t_env *env_list);
int			ft_exit(char **args);
int			is_builtin(t_cmds *cmd, t_tools *t);
char		**c_envp(t_env *env_list);
void		free_2darr(char **tab, t_tools *t);
void		add_oldpwd_tomyenv(char *key, char *value, t_tools *t);
void		print_export(t_tools *t);
int			check_export(char *str);
int			ft_strclen(char *str, char c);
int			count_env_list(t_env *env_list);
int			is_builtin(t_cmds *cmd, t_tools *t);
char		*find_path(char *cmd, char **paths);
char		*ft_strjoin2(char *s1, char *s2);
void		free_list(t_env *env_list);
char		**c_envp(t_env *env_list);
void		exec_builtins(t_cmds *cmd, t_tools *t, int builtin);
void		add_filename_toargs(t_cmds *cmd, char *filename);
void		check_here_doc(t_redir *red);
void		handle_heredoc_norm(t_redir *red, t_cmds *cmd);
void		handle_redirection(t_redir *red, t_cmds *cmd, t_tools *t);
void		handle_input(char *file, t_tools *t, int fd);
void		norm_exec(t_cmds *node, t_tools *t, int *builtin);
void		norm_exec2(int *fd_prev, int *fd, t_cmds *node);
void		norm_exec3(t_cmds *node, int *builtin, t_tools *t);
void		norm_exec4(int *fd_prev, int *fd);
void		norm_exec5(t_cmds *node, t_tools *t, int *builtin, int *fd);
void		signals(void);
void		sig_handler(int sig);

#endif