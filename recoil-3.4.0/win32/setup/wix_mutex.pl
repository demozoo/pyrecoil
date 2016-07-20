# Generate mutual exclusion conditions
@c = qw(recoilwin.ext xnview_recoil.ext imagine.ext imagine64.ext);
@a = map "\$$_=3 OR (\$$_=-1 AND ?$_=3)", @c; # action is install or (action is nothing and already installed)
for $a (@a[0 .. $#a - 1]) {
	@b = @a[++$i .. $#a];
	while (@b) {
		$_ = "(($a) AND (" . shift @b;
		while (@b) {
			$t = "$_ OR $b[0]";
			last if length($t) > 198;
			$_ = $t;
			shift @b;
		}
		print "$_));\n";
	}
}
