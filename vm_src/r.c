
#include "header.h"

void		roc_while1(t_instruc *instruc, int opcode, t_roc *t)
{
	if (t->binary[t->j - 1] == 1 && t->binary[t->j] == 0)
	{
		instruc->type_params[instruc->nb_params] = T_REG;
		instruc->params[instruc->nb_params] = 1;
		t->length += instruc->params[instruc->nb_params];
		instruc->nb_params++;
	}
	else if (t->binary[t->j - 1] == 0 && t->binary[t->j] == 1)
	{
		instruc->type_params[instruc->nb_params] = T_DIR;
		instruc->params[instruc->nb_params] =
			g_instruction[opcode - 1].dir_size;
		t->length += instruc->params[instruc->nb_params];
		instruc->nb_params++;
	}
	else if (t->binary[t->j - 1] == 1 && t->binary[t->j] == 1)
	{
		instruc->type_params[instruc->nb_params] = T_IND;
		instruc->params[instruc->nb_params] = 2;
		t->length += instruc->params[instruc->nb_params];
		instruc->nb_params++;
	}
}

int			read_octet_codage(t_instruc *instruc, int opcode,
				unsigned char codage)
{
	t_roc t;

	t.j = 0;
	while (t.j < 8)
	{
		t.binary[t.j] = codage % 2;
		codage /= 2;
		t.j++;
	}
	t.length = 1;
	t.j = 7;
	instruc->nb_params = 0;
	while (t.j > 0)
	{
		roc_while1(instruc, opcode, &t);
		t.j -= 2;
	}
	return (t.length);
}

void		get_parameters(t_proc **proc, unsigned char *mem)
{
	int				len_tmp;
	unsigned int	i;
	int				a;

	i = 0;
	a = 0;
	while (i < (*proc)->instruc.nb_params)
	{
		len_tmp = (*proc)->instruc.params[i];
		(*proc)->instruc.params[i] = read_unsigned_int(mem + a, len_tmp);
		if ((*proc)->instruc.type_params[i] == T_IND)
		{
			(g_instruction[(*proc)->instruc.opcode - 1].idx == 1) ?
			(*proc)->instruc.params[i] %= IDX_MOD : 0;
			(*proc)->instruc.params[i] =
			((*proc)->instruc.params[i] + (*proc)->pc) % MEM_SIZE;
		}
		a += len_tmp;
		i++;
	}
}

int			init_read_instruction(t_vm *vm, int i, int *opcode, int *len)
{
	*len = 1;
	vm->procs[i]->wait = 0;
	*opcode = vm->mem[vm->procs[i]->pc];
	if (*opcode <= 0 || *opcode > 19)
		return (0);
	else
	{
		vm->procs[i]->wait = g_instruction[*opcode - 1].cycle;
		vm->procs[i]->instruc.opcode = *opcode;
	}
	return (1);
}

int			read_instruction(t_vm *vm, int i)
{
	int opcode;
	int len;

	if (!init_read_instruction(vm, i, &opcode, &len))
		return (len);
	if (g_instruction[opcode - 1].codage)
		len += read_octet_codage(&vm->procs[i]->instruc, opcode,
				vm->mem[vm->procs[i]->pc + 1]);
	else
	{
		vm->procs[i]->instruc.nb_params = 0;
		vm->procs[i]->instruc.
			type_params[vm->procs[i]->instruc.nb_params] = T_DIR;
		vm->procs[i]->instruc.params[vm->procs[i]->instruc.
			nb_params] = g_instruction[opcode - 1].dir_size;
		len += vm->procs[i]->instruc.params[vm->procs[i]->instruc.nb_params];
		vm->procs[i]->instruc.nb_params++;
	}
	get_parameters(&vm->procs[i], (unsigned char *)&vm->mem[vm->procs[i]->pc +
			((g_instruction[opcode - 1].codage) ? 2 : 1)]);
	return (len);
}
