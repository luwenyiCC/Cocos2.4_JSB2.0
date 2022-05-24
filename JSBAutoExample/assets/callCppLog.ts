const { ccclass, property } = cc._decorator;

@ccclass
export default class CallCppLog extends cc.Component {

    // onLoad () {}

    start() {
        this.cppLog()
    }

    cppLog() {
        var level = 2;
        var msg = "abc"
        if (cc.sys.isNative && cc.sys.os === cc.sys.OS_ANDROID) {
            abc.JSBBridge.getInstance().abcLog(level, 'test', msg);
        }
    }

    onClick() {
        this.cppLog()
    }
    // update (dt) {}
}
