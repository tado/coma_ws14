//楽器基本
SynthDef("col_closesaw", {
	arg fadeTime = 10, n = 0, rq = 0.3, detune = 0.001, base = 20, ratio = 1.5, harm = 1.5, amp = 0.2, gate=0;
	var lfo, env, out;
	env = EnvGen.kr(Env.new([0,1], [fadeTime], 'sine'));
	lfo = SinOsc.ar(rrand(0.03, 0.05), 0, 100, 600);
	out = Saw.ar([base+detune.rand, base+detune.rand] * (ratio ** n)) * amp
	+ Saw.ar([base*harm+detune.rand, base*harm+detune.rand] * (ratio ** n)) * amp;
	out = out * env;
	out = RLPF.ar(out, lfo * (1.5 ** n), rq).clip2 * 0.5;
	out = out * EnvGen.kr(Env.adsr(releaseTime:20), gate, doneAction: 2);
	Out.ar(0, out);
}).store;

//テスト
Synth("col_closesaw",["n", 1, "gate", 1]);

//--------------------------------------------------------------------------------------------------------
//エフェクト
SynthDef("col_closefx", {
	arg lpf=440, rq=0.5, amp=0.8;
	var in, out;
	in = In.ar(0, 2);
	12.do({ in = AllpassL.ar(in, 0.1, LFNoise2.kr([rrand(0.0, 0.1),rrand(0.0, 0.1)],0.01,0.06), 4.0) });
	out = CompanderD.ar(in) * amp;
	ReplaceOut.ar(0, out);
}).store;

//エフェクト付きで演奏
Synth("col_closefx");
Synth("col_closesaw",["n", 0, "gate", 1]);

//どんどん倍音を足していく
Synth("col_closesaw",["n", 1, "gate", 1]);
Synth("col_closesaw",["n", 2, "gate", 1]);
Synth("col_closesaw",["n", 3, "gate", 1]);
Synth("col_closesaw",["n", 4, "gate", 1]);
Synth("col_closesaw",["n", 5, "gate", 1]);
Synth("col_closesaw",["n", 6, "gate", 1]);
Synth("col_closesaw",["n", 7, "gate", 1]);
Synth("col_closesaw",["n", 8, "gate", 1]);
Synth("col_closesaw",["n", 9, "gate", 1]);
Synth("col_closesaw",["n", 10, "gate", 1]);
Synth("col_closesaw",["n", 11, "gate", 1]);
...






