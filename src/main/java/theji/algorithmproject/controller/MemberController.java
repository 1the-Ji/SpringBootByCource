package theji.algorithmproject.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import theji.algorithmproject.Member.Member;
import theji.algorithmproject.service.MemberService;

import java.util.List;


@Controller
public class MemberController {

    private final MemberService memberService;
    /*
        스프링 빈을 등록하는 2가지 방법
        1.컴포넌트 스캔과 자동 의존관계 설정
            - @Component 어노테이션이 있으면 스프링 빈으로 자동 등록
            - @Controller, @Service, @Repository
        2.자바 코드로 직접 스프링 빈 등록하기
            - SpringConfig.java 참고
    */

    /*
        DI에는 필드주입 setter 주입, 생성자 주입
     */
    @Autowired
    public MemberController(MemberService memberService){
        this.memberService = memberService;
    }

    @GetMapping(value = "/members/new")
    public String createForm() {
        return "members/createMemberForm";
    }

    @PostMapping(value = "/members/new")
    public String create(MemberForm form) {
        Member member = new Member();
        member.setName(form.getName());
        memberService.join(member);
        return "redirect:/";
    }
    @GetMapping(value = "/members")
    public String list(Model model) {
        List<Member> members = memberService.findMembers();
        model.addAttribute("members", members);
        return "members/memberList";
    }

}
