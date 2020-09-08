package theji.algorithmproject.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import theji.algorithmproject.service.MemberService;

@Controller
public class MemberController {

    private final MemberService memberSerivice;

    @Autowired
    public MemberController(MemberService memberService){
        this.memberSerivice = memberService;
    }

}
